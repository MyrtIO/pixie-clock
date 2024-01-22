#pragma once

#define IO_PROVIDE(T, ...) T T##Instance = T(__VA_ARGS__)
#define IO_PROVIDE_EXTERN(T, ...) extern T T##Instance

#define IO_INJECT(T) &T##Instance
