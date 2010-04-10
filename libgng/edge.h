
#ifndef _EDGE_H
#define _EDGE_H

class Node;

/**
    Edges in the GNG are undirected.  However for ease of
    implementation, the edges are represented as one-way. For example,
    if unitA and unitB and connected, then unitA maintains an edge to
    unitB and unitB maintains an edge to unitA.  Edges also maintain
    their age.  If an edge becomes too old, it will be removed.
*/
class Edge {
  
  public:
    Edge(Node* from, Node* to);
    ~Edge();
    
    Node* from() const;
    Node* to() const;
    
    void incrementAge();
    int age() const;
    void resetAge();
        
  private:
    Node *m_from;
    Node *m_to;
    int m_age;
    
};

#endif // _EDGE_H
