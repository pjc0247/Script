Script
======


Usage
----

인스턴스 얻어오기, 해제하기
```C++
Script *script = Script::getInstance();

Script::releaseInstance();
```



pushValue, popValue, getValue로 값 관리 가능.

```C++
// 값을 설정한다.
script->pushValue("nick", "pjc0247");

// 값을 지운다.
script->popValue("nick");

// 값이 지워져서 없으므로 noValue 리턴
if( script->getValue("nick") == Script::noValue ){
  printf("없는 값\n");
}
```



대본 중간에 #{name}을 삽입하면 name에 맞는 이름의 값을 가져와서 대입.
```C++
script->pushValue("nick", "pjc0247");

// hello pjc0247
script->compile("hello #{nick}");
```




 #{@}를 사용할 경우 뒤의 파라미터에서 순차적으로 값 대입.
```C++
// hello world!
script->compile("hello #{@}#{@}", "world","!");
```




다국어 지원용으로 사용 가능

```C++
const string koMsg = "너 #{psy} 아니?";
const string enMsg = "Do you know #{psy}?";
```
