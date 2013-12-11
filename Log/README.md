# Log

Logs information on standard output streams.

* Colorful: Uses terminal escape codes to output nice colors.
* Modular: Has different log levels - `error`, `warning`, `debug`, `verbose` and `normal`.

## How to use

```c++
// It is a "global" static class.
Log::error("Class foo Method bar");
Log::warning("You shouldn't do that!");

Log::debug("This won't show up!");
Log::debugMode(true);
Log::debug("Now this will");

Log::colors(false);
Log::log("Now it won't have colors");
```

