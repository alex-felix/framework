/*
* Software License Agreement (BSD License)
*
* Copyright (c) 2014,Umeå University
* Copyright (c) 2014,DLO, Wageningen University & Research Center.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above
* copyright notice, this list of conditions and the following
* disclaimer in the documentation and/or other materials provided
* with the distribution.
* * Neither the name of Open Source Robotics Foundation nor
* the names of its contributors may be used to endorse or promote
* products derived from this software without specific prior
* written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#include "ReadyState.h"


/*
*  Starts state machine.
* 
*  From the command line it can be manually triggered by:
*
*     $ rostopic pub /state_machine_start std_tring "start state machine"
*
*/
void ReadyState::startCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Recieved message : %s", msg->data.c_str());
  if (msg->data == "start state machine")
  {
    ROS_INFO("Starting main program.");
    transition = "start";
  }
  else
  { 
    ROS_INFO("Main program not ready yet.");
    transition = "not ready";
  }
}


ReadyState::ReadyState()
{
  transition = "not ready";
  start_subscriber = node_handle.subscribe("state_machine_start", 10, &ReadyState::startCallback, this);
}


std::string ReadyState::execute(std::map<std::string, boost::any> * data)
{
  transition = "not ready";
  ros::Rate rate(1.0);
  rate.sleep();
  return transition;
}
