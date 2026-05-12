#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
	std::vector<StudentGrade> m_map;

public:
	GradeMap(): m_map{}
	{
		
  }
	char& operator[](std::string key)
	{
		// if exist return referece to grade
		auto it = std::find_if(m_map.begin(), m_map.end(),
		                       [key](const StudentGrade& grade)
		                       { return grade.name == key; });

		if (it != m_map.end())
			return it->grade;
		else
		{
			m_map.emplace_back(StudentGrade(key));
			return m_map.back().grade;
    }

		// if not, add StudentGrade for new student, and return reference to grade
	}
};

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
