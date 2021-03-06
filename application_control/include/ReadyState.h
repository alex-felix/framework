#ifndef READYSTATE_H_
#define READYSTATE_H_

#include "State.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

class ReadyState: public State {
	private:
	ros::NodeHandle node_handle;
	ros::Subscriber start_subscriber ;
	std::string transition;
public:
	ReadyState();
	void startCallback(const std_msgs::String::ConstPtr& msg);
	std::string execute(std::map<std::string,boost::any> * data);
};

#endif /* READYSTATE_H_ */
