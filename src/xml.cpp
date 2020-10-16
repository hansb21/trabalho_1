#include "linked_stack.h"
#include <cstddef>
#include <string>

#define ENDPOSITION  end + 1 - start




namespace xml {

bool verifier(const std::string& xml_file) {
	
	structures::LinkedStack<std::string> tags;

	auto counter = 0u;

	while (counter < xml_file.length()) 
	{

		auto start = xml_file.find('<', counter);
		auto end = xml_file.find('>', start);

		if (start == std::string::npos) break;

		if (end == std::string::npos) return false;

		//we get the tag between the start position and the last one.
		auto tag = xml_file.substr(start, ENDPOSITION);
		counter = end + 1;
		
		if (tag[1] != '/') 
		{
			tags.push(tag.insert(1, "/"));

		} else
		{	
			if (tags.empty()) return false;
			else if (tags.top() == tag) tags.pop();
			else return false;
		}
	}
	return tags.empty();
}	

std::string extract(const std::string& origin, const std::string& start, 
		const std::string& end, std::size_t& from)
{		
	auto start_pos = origin.find(start, from);
	const auto end_pos = origin.find(end, start_pos);
	
	if (start_pos == std::string::npos || end_pos == std::string::npos)
	{
		from = std::string::npos;
		return "";
	}
	
	from = end_pos + end.length();
	start_pos += start.length();
	return origin.substr(start_pos, end_pos - start_pos);
}

std::string subextractor(const std::string& origin, const std::string& start, const std::string& close)
{
	std::size_t pos{0};
	return extract(origin, start, close, pos);
}

}  // namespace xml
