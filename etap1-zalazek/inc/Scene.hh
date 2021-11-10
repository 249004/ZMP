#pragma once
#include <map>
#include <string>
#include <memory>
#include "MobileObj.hh"

using namespace std;

typedef map<string, shared_ptr<MobileObj>> SetMobileObj;

class Scene
{
    SetMobileObj mob_obj;

    public:
      Scene();
      ~Scene();

      shared_ptr<MobileObj> FindMobileObj(string pMobObj);
      void AddMobileObj(MobileObj *pMobObj);
};
