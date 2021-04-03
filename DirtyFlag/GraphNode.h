#pragma once

#include "Transform.h"
#include "Mesh.h"

#include <vector>

class GraphNode
{
public:
	GraphNode(Mesh* mesh, const Transform& transform)
		: StaticMesh{ mesh }, Local { transform } {}

	~GraphNode()
	{
		delete StaticMesh;
		for (auto node : Childern)
			delete node;
	}

	void AddChild(GraphNode* child)
	{
		Childern.push_back(child);
	}

	void Render(Transform& parentWorld, bool dirty)
	{
		dirty |= DirtyFlag;
		if (dirty)
		{
			World = Local.combine(parentWorld);
			DirtyFlag = false;
		}

		if (StaticMesh)
			StaticMesh->RenderMesh();

		for (auto node : Childern)
			node->Render(World, dirty);
	}

private:
	Transform World;
	Transform Local;
	bool DirtyFlag{ false };
	Mesh* StaticMesh;
	std::vector<GraphNode*> Childern;
};