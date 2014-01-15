#ifndef SCRIPT_H
#define SCRIPT_H

#include <regex>
#include <string>
#include <map>

class Script{
private:
	static Script *instance;

	Script();
	virtual ~Script();

public:
	static Script *getInstance();
	static void releaseInstance();

public:
	static std::string noValue;

	/*
		pushValue

		밸류 테이블에 값을 삽입합니다.

		key : 키
		value : 값
	*/
	void pushValue(std::string &&key,std::string value);
	/*
		popValue

		밸류 테이블에서 값을 삭제합니다.

		key : 키
	*/
	void popValue(std::string &&key);
	/*
		getValue

		밸류 테이블에서 값을 얻어옵니다.
		값이 없을경우 Script::noValue 반환

		key : 키
	*/
	std::string getValue(std::string &&key);


	/*
		compile

		대본에 값을 대입해서 완성된 스트링을 만듭니다.

		#{name}을 사용하면 name과 같은 키를 가지는 값을 밸류 테이블에서
		가져와서 대입합니다.
		밸류 테이블에 해당 값이 없을 경우 파라미터 리스트에서 가져옵니다.

		script : 대본
		... : 파라미터

		ex)
			compile("hello #{@}", "world"); // hello world

			setValue("name", "pjc");
			compile("hello #{anz}#{@}", "!"); // hello anz!
	*/
	std::string compile(std::string script, ...);

protected:
	std::map<std::string,std::string> values;
};

#endif //SCRIPT_H
