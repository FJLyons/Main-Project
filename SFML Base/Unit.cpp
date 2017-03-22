#include "Unit.h"



Unit::Unit(int type) : m_type(type)
{
	Init();
}


Unit::~Unit()
{
}

void Unit::Init()
{
	m_radius = 20;
	m_circleShape = sf::CircleShape();
	m_circleShape.setRadius(m_radius);
	m_circleShape.setOrigin(sf::Vector2f(m_radius, m_radius));

	if (m_type == 0)
	{
		m_position = sf::Vector2f(100, 540);
		m_circleShape.setPosition(m_position);
		m_circleShape.setFillColor(sf::Color::Blue);
		m_circleShape.setOutlineColor(sf::Color::White);
		m_circleShape.setOutlineThickness(m_radius / 10.0f);

		CreateGOAPActions();
	}

	else
	{
		m_position = sf::Vector2f(1820, 540);
		m_circleShape.setPosition(m_position);
		m_circleShape.setFillColor(sf::Color::Red);
		m_circleShape.setOutlineColor(sf::Color::White);
		m_circleShape.setOutlineThickness(m_radius / 10.0f);

		CreateMCTSActions();
	}

	POV = sf::CircleShape();
	POV.setRadius(m_radius * m_range_sight);
	POV.setOrigin(sf::Vector2f(POV.getRadius(), POV.getRadius()));
	POV.setPosition(m_position);
	POV.setFillColor(sf::Color::Transparent);
	POV.setOutlineColor(sf::Color::Yellow);
	POV.setOutlineThickness(2.0f);

	RANGE = sf::CircleShape();
	RANGE.setRadius(m_radius * m_range_attack);
	RANGE.setOrigin(sf::Vector2f(RANGE.getRadius(), RANGE.getRadius()));
	RANGE.setPosition(m_position);
	RANGE.setFillColor(sf::Color::Transparent);
	RANGE.setOutlineColor(sf::Color::Black);
	RANGE.setOutlineThickness(2.0f);
}

int Unit::Update(ActionState currentState, float dt)
{
	m_circleShape.setPosition(m_position);
	POV.setPosition(m_position);
	RANGE.setPosition(m_position);

	if (currentState == ActionState::Search_for_Castle) { m_working = SearchForCastle(); }
	else if (currentState == ActionState::Castle_Sighted) { m_working = MoveToCastle(); }
	else if (currentState == ActionState::Castle_in_Range) { m_working = CheckCastle(); }
	else if (currentState == ActionState::Attack_Castle) { m_working = AttackCastle(dt); }
	else if (currentState == ActionState::Castle_Dead) { m_working = Win(); }

	return m_working;
}

void Unit::Draw(sf::RenderWindow &window)
{
	window.draw(m_circleShape);
	window.draw(POV);
	window.draw(RANGE);
}

void Unit::CreateGOAPActions()
{
	actions = new std::vector<GOAPAction*>();

	search = new GOAPAction(ActionState::Search_for_Castle, 1);
	search->SetPreconditions(ActionState::Castle_Sighted, false);
	search->SetEffects(ActionState::Castle_Sighted, true);
	search->SetEffects(ActionState::Search_for_Castle, false);
	actions->push_back(search);

	sighted = new GOAPAction(ActionState::Castle_Sighted, 1);
	sighted->SetPreconditions(ActionState::Castle_Sighted, true);
	sighted->SetEffects(ActionState::Castle_in_Range, true);
	actions->push_back(sighted);

	moveTo = new GOAPAction(ActionState::Castle_in_Range, 1);
	moveTo->SetPreconditions(ActionState::Castle_in_Range, true);
	moveTo->SetEffects(ActionState::Attack_Castle, true);
	actions->push_back(moveTo);

	attack = new GOAPAction(ActionState::Attack_Castle, 1);
	attack->SetPreconditions(ActionState::Attack_Castle, true);
	attack->SetEffects(ActionState::Castle_Dead, true);
	actions->push_back(attack);

	win = new GOAPAction(ActionState::Castle_Dead, 1);
	win->SetPreconditions(ActionState::Castle_Dead, true);
	win->SetEffects(ActionState::Search_for_Castle, true);
	actions->push_back(win);
}

void Unit::CreateMCTSActions()
{
	m_actions = new std::vector<MCTSAction*>();
	
	m_search = new MCTSAction();
	m_search->AddChild(ActionState::Search_for_Castle, true);
	m_actions->push_back(m_search);

	m_action = m_search;
}


// Moves
int Unit::SearchForCastle()
{
	if(m_type == 0)
		m_position.x += m_speed_movement; // needs to be wanger function or directional
	else
		m_position.x -= m_speed_movement; // needs to be wanger function or directional


	if (CollisionManager::GetInstance()->CheckUnitPOVCastle(&POV, true))
	{
		return SUCCESS;
	}

	return 0;
}

int Unit::MoveToCastle()
{
	sf::Vector2f direction = CollisionManager::GetInstance()->MoveToCastle(m_position, true);
	m_position += sf::Vector2f(direction.x * m_speed_movement, direction.y * m_speed_movement);

	if (CollisionManager::GetInstance()->CheckUnitCastle(&RANGE, true))
	{
		return SUCCESS;
	}

	return 0;
}

int Unit::CheckCastle()
{
	// check castle variables
	// check surroundings

	if (CollisionManager::GetInstance()->CheckUnitCastle(&RANGE, true))
	{
		return SUCCESS;
	}

	return 0;
}

int Unit::AttackCastle(float dt)
{
	m_attack_timer += dt;

	if (CollisionManager::GetInstance()->CheckUnitCastle(&RANGE, true))
	{
		if (m_attack_timer >= m_speed_attack * 1000)
		{
			m_attack_timer = 0;
			return SUCCESS;
		}


		return 0;
	}

	else
	{
		return FAIL;
	}
}

int Unit::Win()
{
	return SUCCESS;
}
