
#include "edge.h"

using namespace GNG;

static int currentId = 0;

Edge::Edge(GNG::Node* from, GNG::Node* to)
  : m_id(currentId)
{
  currentId++;
  m_from = from;
  m_to = to;
  m_age = 0;
  m_totalAge = 0;
  m_lastUpdated = 0;
}

Edge::~Edge()
{
}

int Edge::id() const
{
  return m_id;
}

GNG::Node* Edge::from() const
{
  return m_from;
}

GNG::Node* Edge::to() const
{
  return m_to;
}

int Edge::age() const
{
  return m_age;
}

void Edge::resetAge()
{
  m_age = 0;
}

void Edge::incrementAge()
{
  m_age++;
}
void Edge::setAge(int age)
{
  m_age = age;
}


int Edge::totalAge() const
{
  return m_totalAge;
}
void Edge::incrementTotalAge()
{
  m_totalAge++;
}

int Edge::lastUpdated()
{
  return m_lastUpdated;
}
void Edge::setLastUpdated(int time)
{
  m_lastUpdated = time;
}


