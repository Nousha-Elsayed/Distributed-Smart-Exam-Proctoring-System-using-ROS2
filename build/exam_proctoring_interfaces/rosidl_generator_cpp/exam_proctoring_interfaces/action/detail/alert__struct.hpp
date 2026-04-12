// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from exam_proctoring_interfaces:action/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "exam_proctoring_interfaces/action/alert.hpp"


#ifndef EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_HPP_
#define EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Goal __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Goal __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_Goal_
{
  using Type = Alert_Goal_<ContainerAllocator>;

  explicit Alert_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->alert_level = 0l;
      this->message = "";
    }
  }

  explicit Alert_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->alert_level = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _alert_level_type =
    int32_t;
  _alert_level_type alert_level;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__alert_level(
    const int32_t & _arg)
  {
    this->alert_level = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Goal
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Goal
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_Goal_ & other) const
  {
    if (this->alert_level != other.alert_level) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_Goal_

// alias to use template instance with default allocator
using Alert_Goal =
  exam_proctoring_interfaces::action::Alert_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Result __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Result __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_Result_
{
  using Type = Alert_Result_<ContainerAllocator>;

  explicit Alert_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->response = "";
    }
  }

  explicit Alert_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->response = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Result
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Result
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_Result_

// alias to use template instance with default allocator
using Alert_Result =
  exam_proctoring_interfaces::action::Alert_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_Feedback __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_Feedback_
{
  using Type = Alert_Feedback_<ContainerAllocator>;

  explicit Alert_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit Alert_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Feedback
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_Feedback
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_Feedback_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_Feedback_

// alias to use template instance with default allocator
using Alert_Feedback =
  exam_proctoring_interfaces::action::Alert_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "exam_proctoring_interfaces/action/detail/alert__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Request __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_SendGoal_Request_
{
  using Type = Alert_SendGoal_Request_<ContainerAllocator>;

  explicit Alert_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Alert_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const exam_proctoring_interfaces::action::Alert_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Request
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Request
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_SendGoal_Request_

// alias to use template instance with default allocator
using Alert_SendGoal_Request =
  exam_proctoring_interfaces::action::Alert_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Response __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_SendGoal_Response_
{
  using Type = Alert_SendGoal_Response_<ContainerAllocator>;

  explicit Alert_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Alert_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Response
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Response
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_SendGoal_Response_

// alias to use template instance with default allocator
using Alert_SendGoal_Response =
  exam_proctoring_interfaces::action::Alert_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Event __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_SendGoal_Event_
{
  using Type = Alert_SendGoal_Event_<ContainerAllocator>;

  explicit Alert_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Alert_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Event
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_SendGoal_Event
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_SendGoal_Event_

// alias to use template instance with default allocator
using Alert_SendGoal_Event =
  exam_proctoring_interfaces::action::Alert_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces

namespace exam_proctoring_interfaces
{

namespace action
{

struct Alert_SendGoal
{
  using Request = exam_proctoring_interfaces::action::Alert_SendGoal_Request;
  using Response = exam_proctoring_interfaces::action::Alert_SendGoal_Response;
  using Event = exam_proctoring_interfaces::action::Alert_SendGoal_Event;
};

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Request __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_GetResult_Request_
{
  using Type = Alert_GetResult_Request_<ContainerAllocator>;

  explicit Alert_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Alert_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Request
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Request
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_GetResult_Request_

// alias to use template instance with default allocator
using Alert_GetResult_Request =
  exam_proctoring_interfaces::action::Alert_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Response __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_GetResult_Response_
{
  using Type = Alert_GetResult_Response_<ContainerAllocator>;

  explicit Alert_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Alert_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const exam_proctoring_interfaces::action::Alert_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Response
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Response
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_GetResult_Response_

// alias to use template instance with default allocator
using Alert_GetResult_Response =
  exam_proctoring_interfaces::action::Alert_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Event __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_GetResult_Event_
{
  using Type = Alert_GetResult_Event_<ContainerAllocator>;

  explicit Alert_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Alert_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<exam_proctoring_interfaces::action::Alert_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Event
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_GetResult_Event
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_GetResult_Event_

// alias to use template instance with default allocator
using Alert_GetResult_Event =
  exam_proctoring_interfaces::action::Alert_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces

namespace exam_proctoring_interfaces
{

namespace action
{

struct Alert_GetResult
{
  using Request = exam_proctoring_interfaces::action::Alert_GetResult_Request;
  using Response = exam_proctoring_interfaces::action::Alert_GetResult_Response;
  using Event = exam_proctoring_interfaces::action::Alert_GetResult_Event;
};

}  // namespace action

}  // namespace exam_proctoring_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__exam_proctoring_interfaces__action__Alert_FeedbackMessage __declspec(deprecated)
#endif

namespace exam_proctoring_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Alert_FeedbackMessage_
{
  using Type = Alert_FeedbackMessage_<ContainerAllocator>;

  explicit Alert_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Alert_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const exam_proctoring_interfaces::action::Alert_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_FeedbackMessage
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exam_proctoring_interfaces__action__Alert_FeedbackMessage
    std::shared_ptr<exam_proctoring_interfaces::action::Alert_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_FeedbackMessage_

// alias to use template instance with default allocator
using Alert_FeedbackMessage =
  exam_proctoring_interfaces::action::Alert_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace exam_proctoring_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace exam_proctoring_interfaces
{

namespace action
{

struct Alert
{
  /// The goal message defined in the action definition.
  using Goal = exam_proctoring_interfaces::action::Alert_Goal;
  /// The result message defined in the action definition.
  using Result = exam_proctoring_interfaces::action::Alert_Result;
  /// The feedback message defined in the action definition.
  using Feedback = exam_proctoring_interfaces::action::Alert_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = exam_proctoring_interfaces::action::Alert_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = exam_proctoring_interfaces::action::Alert_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = exam_proctoring_interfaces::action::Alert_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Alert Alert;

}  // namespace action

}  // namespace exam_proctoring_interfaces

#endif  // EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_HPP_
