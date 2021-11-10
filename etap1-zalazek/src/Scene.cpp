#include "Scene.hh"

Scene::Scene(){}

Scene::~Scene(){}

shared_ptr<MobileObj> Scene::FindMobileObj(string pMobObj) 
{
  auto it = this->mob_obj.find(pMobObj);

  if (it == mob_obj.end()) 
    return nullptr;
  
  return (it->second);
  
}

void Scene::AddMobileObj(MobileObj *pMobObj) 
{

}
