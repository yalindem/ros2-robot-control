// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from carla_msgs:msg/CarlaActorList.idl
// generated code does not contain a copyright notice
#include "carla_msgs/msg/detail/carla_actor_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `actors`
#include "carla_msgs/msg/detail/carla_actor_info__functions.h"

bool
carla_msgs__msg__CarlaActorList__init(carla_msgs__msg__CarlaActorList * msg)
{
  if (!msg) {
    return false;
  }
  // actors
  if (!carla_msgs__msg__CarlaActorInfo__Sequence__init(&msg->actors, 0)) {
    carla_msgs__msg__CarlaActorList__fini(msg);
    return false;
  }
  return true;
}

void
carla_msgs__msg__CarlaActorList__fini(carla_msgs__msg__CarlaActorList * msg)
{
  if (!msg) {
    return;
  }
  // actors
  carla_msgs__msg__CarlaActorInfo__Sequence__fini(&msg->actors);
}

bool
carla_msgs__msg__CarlaActorList__are_equal(const carla_msgs__msg__CarlaActorList * lhs, const carla_msgs__msg__CarlaActorList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // actors
  if (!carla_msgs__msg__CarlaActorInfo__Sequence__are_equal(
      &(lhs->actors), &(rhs->actors)))
  {
    return false;
  }
  return true;
}

bool
carla_msgs__msg__CarlaActorList__copy(
  const carla_msgs__msg__CarlaActorList * input,
  carla_msgs__msg__CarlaActorList * output)
{
  if (!input || !output) {
    return false;
  }
  // actors
  if (!carla_msgs__msg__CarlaActorInfo__Sequence__copy(
      &(input->actors), &(output->actors)))
  {
    return false;
  }
  return true;
}

carla_msgs__msg__CarlaActorList *
carla_msgs__msg__CarlaActorList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  carla_msgs__msg__CarlaActorList * msg = (carla_msgs__msg__CarlaActorList *)allocator.allocate(sizeof(carla_msgs__msg__CarlaActorList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(carla_msgs__msg__CarlaActorList));
  bool success = carla_msgs__msg__CarlaActorList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
carla_msgs__msg__CarlaActorList__destroy(carla_msgs__msg__CarlaActorList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    carla_msgs__msg__CarlaActorList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
carla_msgs__msg__CarlaActorList__Sequence__init(carla_msgs__msg__CarlaActorList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  carla_msgs__msg__CarlaActorList * data = NULL;

  if (size) {
    data = (carla_msgs__msg__CarlaActorList *)allocator.zero_allocate(size, sizeof(carla_msgs__msg__CarlaActorList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = carla_msgs__msg__CarlaActorList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        carla_msgs__msg__CarlaActorList__fini(&data[i - 1]);
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
carla_msgs__msg__CarlaActorList__Sequence__fini(carla_msgs__msg__CarlaActorList__Sequence * array)
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
      carla_msgs__msg__CarlaActorList__fini(&array->data[i]);
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

carla_msgs__msg__CarlaActorList__Sequence *
carla_msgs__msg__CarlaActorList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  carla_msgs__msg__CarlaActorList__Sequence * array = (carla_msgs__msg__CarlaActorList__Sequence *)allocator.allocate(sizeof(carla_msgs__msg__CarlaActorList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = carla_msgs__msg__CarlaActorList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
carla_msgs__msg__CarlaActorList__Sequence__destroy(carla_msgs__msg__CarlaActorList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    carla_msgs__msg__CarlaActorList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
carla_msgs__msg__CarlaActorList__Sequence__are_equal(const carla_msgs__msg__CarlaActorList__Sequence * lhs, const carla_msgs__msg__CarlaActorList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!carla_msgs__msg__CarlaActorList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
carla_msgs__msg__CarlaActorList__Sequence__copy(
  const carla_msgs__msg__CarlaActorList__Sequence * input,
  carla_msgs__msg__CarlaActorList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(carla_msgs__msg__CarlaActorList);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    carla_msgs__msg__CarlaActorList * data =
      (carla_msgs__msg__CarlaActorList *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!carla_msgs__msg__CarlaActorList__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          carla_msgs__msg__CarlaActorList__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!carla_msgs__msg__CarlaActorList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
