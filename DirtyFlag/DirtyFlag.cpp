#include "GraphNode.h"

int main()
{
    Transform BaseTransform{ 0.0 };
    GraphNode* root = new GraphNode(nullptr, Transform{ 0.f });
    GraphNode* ship = new GraphNode(new Mesh(), Transform{ 2.f });
    GraphNode* watchTower = new GraphNode(new Mesh(), Transform{ 3.f });
    GraphNode* pirate = new GraphNode(new Mesh(), Transform{ 4.f });
    GraphNode* parrot = new GraphNode(new Mesh(), Transform{ 4.f });

    root->AddChild(ship);
    ship->AddChild(watchTower);
    watchTower->AddChild(pirate);
    pirate->AddChild(parrot);

    root->Render(BaseTransform, false);
}