// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from carla_ackermann_msgs:msg/EgoVehicleControlMaxima.idl
// generated code does not contain a copyright notice
#include "carla_ackermann_msgs/msg/detail/ego_vehicle_control_maxima__rosidl_typesupport_fastrtps_cpp.hpp"
#include "carla_ackermann_msgs/msg/detail/ego_vehicle_control_maxima__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace carla_ackermann_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_carla_ackermann_msgs
cdr_serialize(
  const carla_ackermann_msgs::msg::EgoVehicleControlMaxima & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: max_steering_angle
  cdr << ros_message.max_steering_angle;
  // Member: max_speed
  cdr << ros_message.max_speed;
  // Member: max_accel
  cdr << ros_message.max_accel;
  // Member: max_decel
  cdr << ros_message.max_decel;
  // Member: min_accel
  cdr << ros_message.min_accel;
  // Member: max_pedal
  cdr << ros_message.max_pedal;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_carla_ackermann_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  carla_ackermann_msgs::msg::EgoVehicleControlMaxima & ros_message)
{
  // Member: max_steering_angle
  cdr >> ros_message.max_steering_angle;

  // Member: max_speed
  cdr >> ros_message.max_speed;

  // Member: max_accel
  cdr >> ros_message.max_accel;

  // Member: max_decel
  cdr >> ros_message.max_decel;

  // Member: min_accel
  cdr >> ros_message.min_accel;

  // Member: max_pedal
  cdr >> ros_message.max_pedal;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_carla_ackermann_msgs
get_serialized_size(
  const carla_ackermann_msgs::msg::EgoVehicleControlMaxima & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: max_steering_angle
  {
    size_t item_size = sizeof(ros_message.max_steering_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_speed
  {
    size_t item_size = sizeof(ros_message.max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_accel
  {
    size_t item_size = sizeof(ros_message.max_accel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_decel
  {
    size_t item_size = sizeof(ros_message.max_decel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: min_accel
  {
    size_t item_size = sizeof(ros_message.min_accel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_pedal
  {
    size_t item_size = sizeof(ros_message.max_pedal);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_carla_ackermann_msgs
max_serialized_size_EgoVehicleControlMaxima(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: max_steering_angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_accel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_decel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: min_accel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_pedal
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = carla_ackermann_msgs::msg::EgoVehicleControlMaxima;
    is_plain =
      (
      offsetof(DataType, max_pedal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _EgoVehicleControlMaxima__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const carla_ackermann_msgs::msg::EgoVehicleControlMaxima *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EgoVehicleControlMaxima__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<carla_ackermann_msgs::msg::EgoVehicleControlMaxima *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EgoVehicleControlMaxima__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const carla_ackermann_msgs::msg::EgoVehicleControlMaxima *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EgoVehicleControlMaxima__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_EgoVehicleControlMaxima(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _EgoVehicleControlMaxima__callbacks = {
  "carla_ackermann_msgs::msg",
  "EgoVehicleControlMaxima",
  _EgoVehicleControlMaxima__cdr_serialize,
  _EgoVehicleControlMaxima__cdr_deserialize,
  _EgoVehicleControlMaxima__get_serialized_size,
  _EgoVehicleControlMaxima__max_serialized_size
};

static rosidl_message_type_support_t _EgoVehicleControlMaxima__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EgoVehicleControlMaxima__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace carla_ackermann_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_carla_ackermann_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<carla_ackermann_msgs::msg::EgoVehicleControlMaxima>()
{
  return &carla_ackermann_msgs::msg::typesupport_fastrtps_cpp::_EgoVehicleControlMaxima__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, carla_ackermann_msgs, msg, EgoVehicleControlMaxima)() {
  return &carla_ackermann_msgs::msg::typesupport_fastrtps_cpp::_EgoVehicleControlMaxima__handle;
}

#ifdef __cplusplus
}
#endif
