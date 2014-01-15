Script
======


Usage
----
```C++
Script *script = Script::getInstance();

script->pushValue("name", "pjc0247");

// hello pjc0247
script->compile("hello #{name}");

// hello world!
script->compile("hello #{@}#{@}", "world","!");
```

```C++
const string koMsg = "너 #{psy} 아니?";
const string enMsg = "Do you know #{psy}?";
```
