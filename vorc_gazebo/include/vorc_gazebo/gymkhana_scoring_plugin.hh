/*
 * Copyright (C) 2020 Open Source Robotics Foundation
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

#ifndef VORC_GAZEBO_GYMKHANA_SCORING_PLUGIN_HH_
#define VORC_GAZEBO_GYMKHANA_SCORING_PLUGIN_HH_

#include <ros/ros.h>
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/World.hh>
#include <vrx_gazebo/scoring_plugin.hh>

class GymkhanaScoringPlugin : public ScoringPlugin
{
  /// \brief Constructor.
  public: GymkhanaScoringPlugin();

  /// \brief Destructor.
  public: virtual ~GymkhanaScoringPlugin();

  // Documentation inherited.
  public: virtual void Load(gazebo::physics::WorldPtr _world,
                            sdf::ElementPtr _sdf);

  /// \brief Update the plugin.
  protected: void OnUpdate();
};

#endif
