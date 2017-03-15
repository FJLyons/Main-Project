#include "Unit.h"



Unit::Unit()
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
	m_circleShape.setOrigin(sf::Vector2f(m_radius / 2, m_radius / 2));
	m_circleShape.setPosition(sf::Vector2f(100, 540));
	m_circleShape.setFillColor(sf::Color::Blue);
	m_circleShape.setOutlineColor(sf::Color::White);
	m_circleShape.setOutlineThickness(m_radius / 10.0f);

	CreateGOAPActions(); 
	CreateMCTSActions();
}

void Unit::Update()
{

}

void Unit::Draw(sf::RenderWindow &window)
{
	window.draw(m_circleShape);
}

void Unit::CreateGOAPActions()
{
	actions = new std::vector<GOAPAction*>();

	search = new GOAPAction(GV->Search_for_Castle, 1);
	search->SetPreconditions(GV->Castle_Sighted, false);
	search->SetEffects(GV->Castle_Sighted, true);
	search->SetEffects(GV->Search_for_Castle, false);
	actions->push_back(search);

	sighted = new GOAPAction(GV->Castle_Sighted, 1);
	sighted->SetPreconditions(GV->Castle_Sighted, true);
	sighted->SetEffects(GV->Castle_in_Range, true);
	actions->push_back(sighted);

	moveTo = new GOAPAction(GV->Castle_in_Range, 1);
	moveTo->SetPreconditions(GV->Castle_in_Range, true);
	moveTo->SetEffects(GV->Attack_Castle, true);
	actions->push_back(moveTo);

	attack = new GOAPAction(GV->Attack_Castle, 1);
	attack->SetPreconditions(GV->Attack_Castle, true);
	attack->SetEffects(GV->Castle_Dead, true);
	actions->push_back(attack);

	win = new GOAPAction(GV->Castle_Dead, 1);
	win->SetPreconditions(GV->Castle_Dead, true);
	win->SetEffects(GV->Search_for_Castle, true);
	actions->push_back(win);
}

void Unit::CreateMCTSActions()
{
	m_actions = new std::vector<MCTSAction*>();
	
	m_search = new MCTSAction();
	m_search->AddChild(GV->Search_for_Castle, true);
	m_actions->push_back(m_search);

	m_action = m_search;
}