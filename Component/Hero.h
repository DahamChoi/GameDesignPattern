#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "InputComponent.h"

class Hero : public GameObject
{
private:
	class HeroInputComponent : public InputComponent
	{
	public:
		HeroInputComponent(GameObject* obj)
			: InputComponent(obj) {}

		void Receive(int message) override
		{

		}

		void Update() override
		{

		}
	};

	class HeroGraphicsComponent : public GraphicsComponent
	{
	public:
		HeroGraphicsComponent(GameObject* obj)
			: GraphicsComponent(obj) {}

		void Receive(int message) override
		{

		}

		void Update() override
		{

		}
	};

	class HeroPhysicsComponent : public PhysicsComponent
	{
	public:
		HeroPhysicsComponent(GameObject* obj)
			: PhysicsComponent(obj) {}

		void Receive(int message) override
		{

		}

		void Update() override
		{

		}
	};

public:
	Hero()
	{
		ComponentList.push_back(new HeroInputComponent(this));
		ComponentList.push_back(new HeroGraphicsComponent(this));
		ComponentList.push_back(new HeroPhysicsComponent(this));
	}

	void Update() override
	{
		GameObject::Update();


	}
};