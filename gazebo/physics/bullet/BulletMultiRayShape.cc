/*
 * Copyright (C) 2012-2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "gazebo/common/Exception.hh"

#include "gazebo/physics/MultiRayShapePrivate.hh"
#include "gazebo/physics/World.hh"
#include "gazebo/physics/bullet/BulletTypes.hh"
#include "gazebo/physics/bullet/BulletLink.hh"
#include "gazebo/physics/bullet/BulletCollision.hh"
#include "gazebo/physics/bullet/BulletPhysics.hh"
#include "gazebo/physics/bullet/BulletRayShape.hh"
#include "gazebo/physics/bullet/BulletMultiRayShape.hh"

using namespace gazebo;
using namespace physics;

//////////////////////////////////////////////////
BulletMultiRayShape::BulletMultiRayShape(CollisionPtr _parent)
: MultiRayShape(_parent)
{
  this->SetName("Bullet Multiray Shape");
  this->physicsEngine = std::static_pointer_cast<BulletPhysics>(
      this->multiRayShapeDPtr->collisionParent->World()->GetPhysicsEngine());
}

//////////////////////////////////////////////////
BulletMultiRayShape::~BulletMultiRayShape()
{
}

//////////////////////////////////////////////////
void BulletMultiRayShape::UpdateRays()
{
  std::vector<RayShapePtr>::iterator iter;
  for (iter = this->multiRayShapeDPtr->rays.begin();
       iter != this->multiRayShapeDPtr->rays.end(); ++iter)
  {
    (*iter)->Update();
  }
}

//////////////////////////////////////////////////
void BulletMultiRayShape::AddRay(const ignition::math::Vector3d &_start,
    const ignition::math::Vector3d &_end)
{
  MultiRayShape::AddRay(_start, _end);

  BulletRayShapePtr ray(new BulletRayShape(
        this->multiRayShapeDPtr->collisionParent));
  ray->SetPoints(_start, _end);

  this->multiRayShapeDPtr->rays.push_back(ray);
}
