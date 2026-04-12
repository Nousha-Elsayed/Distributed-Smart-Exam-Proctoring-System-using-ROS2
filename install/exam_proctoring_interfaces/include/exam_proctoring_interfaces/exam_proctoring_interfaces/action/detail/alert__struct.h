// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from exam_proctoring_interfaces:action/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "exam_proctoring_interfaces/action/alert.h"


#ifndef EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_H_
#define EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_Goal
{
  int32_t alert_level;
  rosidl_runtime_c__String message;
} exam_proctoring_interfaces__action__Alert_Goal;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_Goal.
typedef struct exam_proctoring_interfaces__action__Alert_Goal__Sequence
{
  exam_proctoring_interfaces__action__Alert_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_Result
{
  bool success;
  rosidl_runtime_c__String response;
} exam_proctoring_interfaces__action__Alert_Result;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_Result.
typedef struct exam_proctoring_interfaces__action__Alert_Result__Sequence
{
  exam_proctoring_interfaces__action__Alert_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_Feedback
{
  rosidl_runtime_c__String status;
} exam_proctoring_interfaces__action__Alert_Feedback;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_Feedback.
typedef struct exam_proctoring_interfaces__action__Alert_Feedback__Sequence
{
  exam_proctoring_interfaces__action__Alert_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "exam_proctoring_interfaces/action/detail/alert__struct.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  exam_proctoring_interfaces__action__Alert_Goal goal;
} exam_proctoring_interfaces__action__Alert_SendGoal_Request;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_SendGoal_Request.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence
{
  exam_proctoring_interfaces__action__Alert_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} exam_proctoring_interfaces__action__Alert_SendGoal_Response;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_SendGoal_Response.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence
{
  exam_proctoring_interfaces__action__Alert_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  exam_proctoring_interfaces__action__Alert_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  exam_proctoring_interfaces__action__Alert_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence request;
  exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence response;
} exam_proctoring_interfaces__action__Alert_SendGoal_Event;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_SendGoal_Event.
typedef struct exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence
{
  exam_proctoring_interfaces__action__Alert_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} exam_proctoring_interfaces__action__Alert_GetResult_Request;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_GetResult_Request.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence
{
  exam_proctoring_interfaces__action__Alert_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__struct.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Response
{
  int8_t status;
  exam_proctoring_interfaces__action__Alert_Result result;
} exam_proctoring_interfaces__action__Alert_GetResult_Response;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_GetResult_Response.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence
{
  exam_proctoring_interfaces__action__Alert_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  exam_proctoring_interfaces__action__Alert_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  exam_proctoring_interfaces__action__Alert_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence request;
  exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence response;
} exam_proctoring_interfaces__action__Alert_GetResult_Event;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_GetResult_Event.
typedef struct exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence
{
  exam_proctoring_interfaces__action__Alert_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__struct.h"

/// Struct defined in action/Alert in the package exam_proctoring_interfaces.
typedef struct exam_proctoring_interfaces__action__Alert_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  exam_proctoring_interfaces__action__Alert_Feedback feedback;
} exam_proctoring_interfaces__action__Alert_FeedbackMessage;

// Struct for a sequence of exam_proctoring_interfaces__action__Alert_FeedbackMessage.
typedef struct exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence
{
  exam_proctoring_interfaces__action__Alert_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXAM_PROCTORING_INTERFACES__ACTION__DETAIL__ALERT__STRUCT_H_
