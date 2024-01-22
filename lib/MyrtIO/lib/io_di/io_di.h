#pragma once

#define ioProvide(T, ...) T T##Instance = T(__VA_ARGS__)
#define ioProvideExtern(T, ...) extern T T##Instance

#define ioInject(T) &T##Instance
