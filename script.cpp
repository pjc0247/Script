#include "script.h"

#include <stdarg.h>

using namespace std;

Script *Script::instance = nullptr;
std::string Script::noValue = "noValue";

Script::Script(){
}
Script::~Script(){
}
Script *Script::getInstance(){
	if( instance == nullptr )
		instance = new Script();
	return instance;
}
void Script::releaseInstance(){
	if( instance != nullptr ){
		delete instance;
		instance = nullptr;
	}
}

std::string Script::compile(std::string script, ...){
	const regex sep("#\\{([^\\}]*)\\}");

	va_list val;
	smatch match;

	va_start(val, script);

	while( regex_search(script, match, sep) ){
		auto &value = getValue( match[1].str() );
		std::string replace_to;

		// values에서 대입
		if( value != noValue )
			replace_to.assign( value );
		// param에서 대입
		else{
			replace_to.assign(
				va_arg(val, const char *) );
		}

		script = regex_replace(
			script, sep, replace_to,
			regex_constants::format_first_only);
	}
	
	va_end(val);

	return script;
}

void Script::pushValue(std::string &&key,std::string value){
	values[key] = value;
}
void Script::popValue(std::string &&key){
	values.erase( key );
}
std::string Script::getValue(std::string &&key){
	auto &v = values.find(key);

	if( v == values.end() )
		return noValue;
	else
		return v->second;
}
