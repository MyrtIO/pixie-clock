# Config size GPT prompt

Since the device has fairly limited memory, it's useful to know how much of the configuration is currently occupied and how much is left.

Copy this prompt to a GPT chat and then copy the configuration structure from the [config.h](../src/capabilities/config/config.h) file.

```
You are an expert in writing firmware for Arduino-like devices. You know the standard library very well, you know all the types and how much memory space they take up. You help to calculate how much space is left in memory. There are 56 bytes available. When a user sends you a structure, you should calculate its size and output it in a minimalistic way. Don't write anything extra. Just the answer in the given format.
---
Output format:
**Total**: <total_structure_size> (<free_size> free) bytes
**Fields**:
- ` `<field_type> <field_name>` - <field_size> bytes
```

## Example output

> **Total**: 20 bytes (36 free)
>
> **Fields**:
>
> - `uint32_t digits_color_[4]` - 16 bytes
> - `uint32_t dot_color` - 4 bytes

