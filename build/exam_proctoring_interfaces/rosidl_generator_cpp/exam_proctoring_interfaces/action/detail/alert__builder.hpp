// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from exam_proctoring_interfaces:action/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "exam_proctoring_interfaces/action/alert.hpp"


#ifndef EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__BUILDER_HPP_
#define EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "exam_proctoring_interfaces/action/detail/alert__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_Goal_message
{
public:
  explicit Init_Alert_Goal_message(::exam_proctoring_interfaces::action::Alert_Goal & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_Goal message(::exam_proctoring_interfaces::action::Alert_Goal::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_Goal msg_;
};

class Init_Alert_Goal_alert_level
{
public:
  Init_Alert_Goal_alert_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_Goal_message alert_level(::exam_proctoring_interfaces::action::Alert_Goal::_alert_level_type arg)
  {
    msg_.alert_level = std::move(arg);
    return Init_Alert_Goal_message(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_Goal>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_Goal_alert_level();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_Result_response
{
public:
  explicit Init_Alert_Result_response(::exam_proctoring_interfaces::action::Alert_Result & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_Result response(::exam_proctoring_interfaces::action::Alert_Result::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_Result msg_;
};

class Init_Alert_Result_success
{
public:
  Init_Alert_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_Result_response success(::exam_proctoring_interfaces::action::Alert_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Alert_Result_response(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_Result>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_Result_success();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_Feedback_status
{
public:
  Init_Alert_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::exam_proctoring_interfaces::action::Alert_Feedback status(::exam_proctoring_interfaces::action::Alert_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_Feedback>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_Feedback_status();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_SendGoal_Request_goal
{
public:
  explicit Init_Alert_SendGoal_Request_goal(::exam_proctoring_interfaces::action::Alert_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Request goal(::exam_proctoring_interfaces::action::Alert_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Request msg_;
};

class Init_Alert_SendGoal_Request_goal_id
{
public:
  Init_Alert_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_SendGoal_Request_goal goal_id(::exam_proctoring_interfaces::action::Alert_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Alert_SendGoal_Request_goal(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_SendGoal_Request>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_SendGoal_Request_goal_id();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_SendGoal_Response_stamp
{
public:
  explicit Init_Alert_SendGoal_Response_stamp(::exam_proctoring_interfaces::action::Alert_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Response stamp(::exam_proctoring_interfaces::action::Alert_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Response msg_;
};

class Init_Alert_SendGoal_Response_accepted
{
public:
  Init_Alert_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_SendGoal_Response_stamp accepted(::exam_proctoring_interfaces::action::Alert_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Alert_SendGoal_Response_stamp(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_SendGoal_Response>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_SendGoal_Response_accepted();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_SendGoal_Event_response
{
public:
  explicit Init_Alert_SendGoal_Event_response(::exam_proctoring_interfaces::action::Alert_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Event response(::exam_proctoring_interfaces::action::Alert_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Event msg_;
};

class Init_Alert_SendGoal_Event_request
{
public:
  explicit Init_Alert_SendGoal_Event_request(::exam_proctoring_interfaces::action::Alert_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Alert_SendGoal_Event_response request(::exam_proctoring_interfaces::action::Alert_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Alert_SendGoal_Event_response(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Event msg_;
};

class Init_Alert_SendGoal_Event_info
{
public:
  Init_Alert_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_SendGoal_Event_request info(::exam_proctoring_interfaces::action::Alert_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Alert_SendGoal_Event_request(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_SendGoal_Event>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_SendGoal_Event_info();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_GetResult_Request_goal_id
{
public:
  Init_Alert_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::exam_proctoring_interfaces::action::Alert_GetResult_Request goal_id(::exam_proctoring_interfaces::action::Alert_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_GetResult_Request>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_GetResult_Request_goal_id();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_GetResult_Response_result
{
public:
  explicit Init_Alert_GetResult_Response_result(::exam_proctoring_interfaces::action::Alert_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_GetResult_Response result(::exam_proctoring_interfaces::action::Alert_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Response msg_;
};

class Init_Alert_GetResult_Response_status
{
public:
  Init_Alert_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_GetResult_Response_result status(::exam_proctoring_interfaces::action::Alert_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Alert_GetResult_Response_result(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_GetResult_Response>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_GetResult_Response_status();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_GetResult_Event_response
{
public:
  explicit Init_Alert_GetResult_Event_response(::exam_proctoring_interfaces::action::Alert_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_GetResult_Event response(::exam_proctoring_interfaces::action::Alert_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Event msg_;
};

class Init_Alert_GetResult_Event_request
{
public:
  explicit Init_Alert_GetResult_Event_request(::exam_proctoring_interfaces::action::Alert_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Alert_GetResult_Event_response request(::exam_proctoring_interfaces::action::Alert_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Alert_GetResult_Event_response(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Event msg_;
};

class Init_Alert_GetResult_Event_info
{
public:
  Init_Alert_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_GetResult_Event_request info(::exam_proctoring_interfaces::action::Alert_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Alert_GetResult_Event_request(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_GetResult_Event>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_GetResult_Event_info();
}

}  // namespace exam_proctoring_interfaces


namespace exam_proctoring_interfaces
{

namespace action
{

namespace builder
{

class Init_Alert_FeedbackMessage_feedback
{
public:
  explicit Init_Alert_FeedbackMessage_feedback(::exam_proctoring_interfaces::action::Alert_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::exam_proctoring_interfaces::action::Alert_FeedbackMessage feedback(::exam_proctoring_interfaces::action::Alert_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_FeedbackMessage msg_;
};

class Init_Alert_FeedbackMessage_goal_id
{
public:
  Init_Alert_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_FeedbackMessage_feedback goal_id(::exam_proctoring_interfaces::action::Alert_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Alert_FeedbackMessage_feedback(msg_);
  }

private:
  ::exam_proctoring_interfaces::action::Alert_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::exam_proctoring_interfaces::action::Alert_FeedbackMessage>()
{
  return exam_proctoring_interfaces::action::builder::Init_Alert_FeedbackMessage_goal_id();
}

}  // namespace exam_proctoring_interfaces

#endif  // EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__BUILDER_HPP_
