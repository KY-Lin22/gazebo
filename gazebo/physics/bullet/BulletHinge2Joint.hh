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
#ifndef _GAZEBO_PHYSICS_BULLET_BULLETHINGE2JOINT_HH_
#define _GAZEBO_PHYSICS_BULLET_BULLETHINGE2JOINT_HH_

#include "gazebo/physics/Hinge2Joint.hh"
#include "gazebo/physics/bullet/BulletJoint.hh"
#include "gazebo/physics/bullet/BulletPhysics.hh"
#include "gazebo/util/system.hh"

class btHinge2Constraint;

namespace gazebo
{
  namespace physics
  {
    /// \ingroup gazebo_physics
    /// \addtogroup gazebo_physics_bullet Bullet Physics
    /// \{

    /// \brief A two axis hinge joint
    class GZ_PHYSICS_VISIBLE BulletHinge2Joint : public Hinge2Joint<BulletJoint>
    {
      /// \brief Constructor
      public: BulletHinge2Joint(btDynamicsWorld *world, BasePtr _parent);

      /// \brief Destructor
      public: virtual ~BulletHinge2Joint();

      // Documentation inherited.
      protected: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited.
      public: virtual void Init();

      // Documentation inherited.
      public: virtual ignition::math::Vector3d Anchor(
                  const unsigned int _index) const;

      // Documentation inherited.
      public: virtual void SetAxis(const unsigned int _index,
                  const ignition::math::Vector3d &_axis);

      // Documentation inherited.
      public: virtual ignition::math::Vector3d Axis(
                  const unsigned int _index) const;

      // Documentation inherited.
      public: ignition::math::Angle Angle(const unsigned int _index) const;

      // Documentation inherited.
      public: double Velocity(const unsigned int _index) const;

      // Documentation inherited.
      public: virtual void SetVelocity(const unsigned int _index,
                  const double _angle);

      // Documentation inherited.
      public: virtual bool SetHighStop(const unsigned int _index,
                  const ignition::math::Angle &_angle);

      // Documentation inherited.
      public: virtual bool SetLowStop(const unsigned int _index,
                  const ignition::math::Angle &_angle);

      // Documentation inherited.
      public: virtual ignition::math::Angle HighStop(
                  const unsigned int _index) const;

      // Documentation inherited.
      public: virtual ignition::math::Angle LowStop(
                  const unsigned int _index) const;

      // Documentation inherited.
      public: virtual ignition::math::Vector3d GlobalAxis(
                  const unsigned int _index) const;

      // Documentation inherited.
      public: virtual ignition::math::Angle AngleImpl(
                  const unsigned int _index) const;

      // Documentation inherited.
      protected: virtual void SetForceImpl(
                     const unsigned int _index, const double _torque);

      /// \brief Pointer to bullet hinge2 constraint
      private: btHinge2Constraint *bulletHinge2;

      /// \brief Offset angle used in GetAngleImpl, so that angles are reported
      /// relative to the initial configuration.
      private: double angleOffset[2];

      /// \brief Initial value of joint axis, expressed as unit vector
      /// in world frame.
      private: ignition::math::Vector3d initialWorldAxis[2];
    };

  /// \}
  }
}
#endif
