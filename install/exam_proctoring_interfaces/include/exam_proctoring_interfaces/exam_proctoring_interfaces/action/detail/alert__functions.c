// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exam_proctoring_interfaces:action/Alert.idl
// generated code does not contain a copyright notice
#include "exam_proctoring_interfaces/action/detail/alert__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
exam_proctoring_interfaces__action__Alert_Goal__init(exam_proctoring_interfaces__action__Alert_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // alert_level
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    exam_proctoring_interfaces__action__Alert_Goal__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Goal__fini(exam_proctoring_interfaces__action__Alert_Goal * msg)
{
  if (!msg) {
    return;
  }
  // alert_level
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
exam_proctoring_interfaces__action__Alert_Goal__are_equal(const exam_proctoring_interfaces__action__Alert_Goal * lhs, const exam_proctoring_interfaces__action__Alert_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alert_level
  if (lhs->alert_level != rhs->alert_level) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Goal__copy(
  const exam_proctoring_interfaces__action__Alert_Goal * input,
  exam_proctoring_interfaces__action__Alert_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // alert_level
  output->alert_level = input->alert_level;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_Goal *
exam_proctoring_interfaces__action__Alert_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Goal * msg = (exam_proctoring_interfaces__action__Alert_Goal *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_Goal));
  bool success = exam_proctoring_interfaces__action__Alert_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_Goal__destroy(exam_proctoring_interfaces__action__Alert_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_Goal__Sequence__init(exam_proctoring_interfaces__action__Alert_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Goal * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_Goal *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Goal__Sequence__fini(exam_proctoring_interfaces__action__Alert_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_Goal__Sequence *
exam_proctoring_interfaces__action__Alert_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Goal__Sequence * array = (exam_proctoring_interfaces__action__Alert_Goal__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_Goal__Sequence__destroy(exam_proctoring_interfaces__action__Alert_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_Goal__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_Goal__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Goal__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_Goal__Sequence * input,
  exam_proctoring_interfaces__action__Alert_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_Goal * data =
      (exam_proctoring_interfaces__action__Alert_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
exam_proctoring_interfaces__action__Alert_Result__init(exam_proctoring_interfaces__action__Alert_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    exam_proctoring_interfaces__action__Alert_Result__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Result__fini(exam_proctoring_interfaces__action__Alert_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
exam_proctoring_interfaces__action__Alert_Result__are_equal(const exam_proctoring_interfaces__action__Alert_Result * lhs, const exam_proctoring_interfaces__action__Alert_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Result__copy(
  const exam_proctoring_interfaces__action__Alert_Result * input,
  exam_proctoring_interfaces__action__Alert_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_Result *
exam_proctoring_interfaces__action__Alert_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Result * msg = (exam_proctoring_interfaces__action__Alert_Result *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_Result));
  bool success = exam_proctoring_interfaces__action__Alert_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_Result__destroy(exam_proctoring_interfaces__action__Alert_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_Result__Sequence__init(exam_proctoring_interfaces__action__Alert_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Result * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_Result *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Result__Sequence__fini(exam_proctoring_interfaces__action__Alert_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_Result__Sequence *
exam_proctoring_interfaces__action__Alert_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Result__Sequence * array = (exam_proctoring_interfaces__action__Alert_Result__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_Result__Sequence__destroy(exam_proctoring_interfaces__action__Alert_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_Result__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_Result__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Result__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_Result__Sequence * input,
  exam_proctoring_interfaces__action__Alert_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_Result * data =
      (exam_proctoring_interfaces__action__Alert_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
exam_proctoring_interfaces__action__Alert_Feedback__init(exam_proctoring_interfaces__action__Alert_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    exam_proctoring_interfaces__action__Alert_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Feedback__fini(exam_proctoring_interfaces__action__Alert_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
exam_proctoring_interfaces__action__Alert_Feedback__are_equal(const exam_proctoring_interfaces__action__Alert_Feedback * lhs, const exam_proctoring_interfaces__action__Alert_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Feedback__copy(
  const exam_proctoring_interfaces__action__Alert_Feedback * input,
  exam_proctoring_interfaces__action__Alert_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_Feedback *
exam_proctoring_interfaces__action__Alert_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Feedback * msg = (exam_proctoring_interfaces__action__Alert_Feedback *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_Feedback));
  bool success = exam_proctoring_interfaces__action__Alert_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_Feedback__destroy(exam_proctoring_interfaces__action__Alert_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__init(exam_proctoring_interfaces__action__Alert_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Feedback * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_Feedback *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__fini(exam_proctoring_interfaces__action__Alert_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_Feedback__Sequence *
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_Feedback__Sequence * array = (exam_proctoring_interfaces__action__Alert_Feedback__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__destroy(exam_proctoring_interfaces__action__Alert_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_Feedback__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_Feedback__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_Feedback__Sequence * input,
  exam_proctoring_interfaces__action__Alert_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_Feedback * data =
      (exam_proctoring_interfaces__action__Alert_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__functions.h"

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__init(exam_proctoring_interfaces__action__Alert_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!exam_proctoring_interfaces__action__Alert_Goal__init(&msg->goal)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  exam_proctoring_interfaces__action__Alert_Goal__fini(&msg->goal);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Request * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!exam_proctoring_interfaces__action__Alert_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Request * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!exam_proctoring_interfaces__action__Alert_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_SendGoal_Request *
exam_proctoring_interfaces__action__Alert_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Request * msg = (exam_proctoring_interfaces__action__Alert_SendGoal_Request *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Request));
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Request__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__init(exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Request * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_SendGoal_Request *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence *
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * array = (exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_SendGoal_Request * data =
      (exam_proctoring_interfaces__action__Alert_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__init(exam_proctoring_interfaces__action__Alert_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Response * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Response * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_SendGoal_Response *
exam_proctoring_interfaces__action__Alert_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Response * msg = (exam_proctoring_interfaces__action__Alert_SendGoal_Response *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Response));
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Response__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__init(exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Response * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_SendGoal_Response *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence *
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * array = (exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_SendGoal_Response * data =
      (exam_proctoring_interfaces__action__Alert_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__functions.h"

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__init(exam_proctoring_interfaces__action__Alert_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Event * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Event * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_SendGoal_Event *
exam_proctoring_interfaces__action__Alert_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Event * msg = (exam_proctoring_interfaces__action__Alert_SendGoal_Event *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Event));
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Event__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__init(exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Event * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_SendGoal_Event *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__fini(exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence *
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * array = (exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__destroy(exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * input,
  exam_proctoring_interfaces__action__Alert_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_SendGoal_Event * data =
      (exam_proctoring_interfaces__action__Alert_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__init(exam_proctoring_interfaces__action__Alert_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(exam_proctoring_interfaces__action__Alert_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Request * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Request * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_GetResult_Request *
exam_proctoring_interfaces__action__Alert_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Request * msg = (exam_proctoring_interfaces__action__Alert_GetResult_Request *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Request));
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Request__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__init(exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Request * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_GetResult_Request *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__fini(exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence *
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * array = (exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_GetResult_Request * data =
      (exam_proctoring_interfaces__action__Alert_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__functions.h"

bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__init(exam_proctoring_interfaces__action__Alert_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!exam_proctoring_interfaces__action__Alert_Result__init(&msg->result)) {
    exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(exam_proctoring_interfaces__action__Alert_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  exam_proctoring_interfaces__action__Alert_Result__fini(&msg->result);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Response * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!exam_proctoring_interfaces__action__Alert_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Response * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!exam_proctoring_interfaces__action__Alert_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_GetResult_Response *
exam_proctoring_interfaces__action__Alert_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Response * msg = (exam_proctoring_interfaces__action__Alert_GetResult_Response *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Response));
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Response__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__init(exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Response * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_GetResult_Response *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__fini(exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence *
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * array = (exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_GetResult_Response * data =
      (exam_proctoring_interfaces__action__Alert_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__functions.h"

bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__init(exam_proctoring_interfaces__action__Alert_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__init(&msg->request, 0)) {
    exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__init(&msg->response, 0)) {
    exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(exam_proctoring_interfaces__action__Alert_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__fini(&msg->request);
  // response
  exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__fini(&msg->response);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Event * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Event * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!exam_proctoring_interfaces__action__Alert_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_GetResult_Event *
exam_proctoring_interfaces__action__Alert_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Event * msg = (exam_proctoring_interfaces__action__Alert_GetResult_Event *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Event));
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Event__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__init(exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Event * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_GetResult_Event *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__fini(exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence *
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * array = (exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__destroy(exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * input,
  exam_proctoring_interfaces__action__Alert_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_GetResult_Event * data =
      (exam_proctoring_interfaces__action__Alert_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "exam_proctoring_interfaces/action/detail/alert__functions.h"

bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__init(exam_proctoring_interfaces__action__Alert_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!exam_proctoring_interfaces__action__Alert_Feedback__init(&msg->feedback)) {
    exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(exam_proctoring_interfaces__action__Alert_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  exam_proctoring_interfaces__action__Alert_Feedback__fini(&msg->feedback);
}

bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__are_equal(const exam_proctoring_interfaces__action__Alert_FeedbackMessage * lhs, const exam_proctoring_interfaces__action__Alert_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!exam_proctoring_interfaces__action__Alert_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__copy(
  const exam_proctoring_interfaces__action__Alert_FeedbackMessage * input,
  exam_proctoring_interfaces__action__Alert_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!exam_proctoring_interfaces__action__Alert_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

exam_proctoring_interfaces__action__Alert_FeedbackMessage *
exam_proctoring_interfaces__action__Alert_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_FeedbackMessage * msg = (exam_proctoring_interfaces__action__Alert_FeedbackMessage *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exam_proctoring_interfaces__action__Alert_FeedbackMessage));
  bool success = exam_proctoring_interfaces__action__Alert_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
exam_proctoring_interfaces__action__Alert_FeedbackMessage__destroy(exam_proctoring_interfaces__action__Alert_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__init(exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_FeedbackMessage * data = NULL;

  if (size) {
    data = (exam_proctoring_interfaces__action__Alert_FeedbackMessage *)allocator.zero_allocate(size, sizeof(exam_proctoring_interfaces__action__Alert_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exam_proctoring_interfaces__action__Alert_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__fini(exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence *
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * array = (exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence *)allocator.allocate(sizeof(exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__destroy(exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__are_equal(const exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * lhs, const exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence__copy(
  const exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * input,
  exam_proctoring_interfaces__action__Alert_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(exam_proctoring_interfaces__action__Alert_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    exam_proctoring_interfaces__action__Alert_FeedbackMessage * data =
      (exam_proctoring_interfaces__action__Alert_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!exam_proctoring_interfaces__action__Alert_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          exam_proctoring_interfaces__action__Alert_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!exam_proctoring_interfaces__action__Alert_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
