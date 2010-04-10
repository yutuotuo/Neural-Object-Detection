
#ifndef _GROWINGNEURALGAS_H
#define _GROWINGNEURALGAS_H

class Node;
class Edge;
class PointGenerator;

#include "point.h"

#include <QPair>
#include <QList>
#include <QString>

class GrowingNeuralGas {
  public:
    GrowingNeuralGas(int dimension, qreal minimum, qreal maximum);
    ~GrowingNeuralGas();
    
    QString toString();
    
    bool unitOfInterest(Node *node, qreal cutoff);
    
    /** Computes the distances between the given point and every unit
        in the GNG.  Returns the closest and next closest units. */
    QPair<Node*, Node*> computeDistances(const Point& point); // find 2 best nodes
    
    /** Increments the ages of every unit directly connected to the given unit. */
    void incrementEdgeAges(Node *node);
    
    /** Adds the appropriate edges to connect units a and b. */
    void connectNodes(Node *a, Node *b);
    
    /** Removes the appropriate edges to disconnect units a and b. */
    void disconnectNodes(Node *a, Node *b);
    
    /** Checks all edges in the GNG and removes any with an age exceeding
        the maxAge parameter.  Also removes any unit that is completely
        disconnected. */
    void removeStaleEdges();
    
    /** Given a list of units, returns the unit with the highest error. */
    Node* maxErrorNode(QList<Node*> nodeList);
    
    /** Returns the average error across all units in the GNG. */
    qreal averageError();
    
    /** Inserts a new unit into the GNG.  Finds the unit with the highest
        error and then finds its topological neighbor with the highest
        error and inserts the new unit between the two. */
    void insertNode();
    
    /** Decays the error at all units. */
    void reduceAllErrors();
    
    /** Processes one input point at a time through the GNG. */
    void step(const Point &nextPoint);
    void run(int cycles, PointGenerator *pointGenerator); //FIXME            
    void saveCurrentData(const Point &nextPoint);
    
  private:
    int m_dimension;
    //int m_seed;
    qreal m_winnerLearnRate; /**< Used to adjust closest unit towards input point */
    qreal m_neighborLearnRate; /**< Used to adjust other neighbors towards input point */
    int m_maxAge; /**< Edges older than maxAge are removed */
    qreal m_reduceError; /**< All errors are reduced by this amount each GNG step */
    int m_stepsToInsert; /**< Min steps before inserting a new node */
    int m_stepsSinceLastInsert;
    qreal m_insertError; /**< Error of every new unit is reduced by this amount */
    int m_stepCount;
    QList<Node*> m_nodes;
    QList<Edge*> m_uniqueEdges;
};
      




#endif //_GROWINGNEURALGAS_H