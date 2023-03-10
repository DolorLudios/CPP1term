#include <iostream>
#include <string_view>
#include <vector>
#include <string>

class Time {
private:
	int nHours, nMinutes, nSeconds;
public:
	Time(int hours, int minutes, int seconds) { nHours = hours; nMinutes = minutes; nSeconds = seconds;}
	Time(std::string_view s) {
		int i = 0;
		nHours = std::stoi(std::string(s.substr(i, 2)));
		i += 3;
		nMinutes = std::stoi(std::string(s.substr(i, 2)));
		i += 3;
		nSeconds = std::stoi(std::string(s.substr(i, 2)));
	}
	Time operator+(Time b) const;
	const int hours() { return nHours; }
	const int minutes() { return nMinutes; }
	const int seconds() { return nSeconds; };
	friend std::ostream& operator<<(std::ostream& out, Time t) {
		out << t.hours() << ":" << t.minutes() << ":" << t.seconds();

		return out;
	}
	static Time sumTimes(const std::vector<Time>& v);

	std::vector<Time> getTimesFromString(std::string_view s) {
		std::vector<Time> Times;
		int spaceInd = 0;
		int Ind = 0;
		while (spaceInd <= s.length()) {
			spaceInd = s.find(' ', Ind);

			if (spaceInd == s.length()) {
				spaceInd = s.length();
			}

			std::string_view time = s.substr(Ind, spaceInd - Ind);
			Times.push_back(time);

			Ind = spaceInd + 1;
		}
		return Times;
	}
};

Time Time::sumTimes(const std::vector<Time>& v) {
		int hours;
		int minutes;
		int seconds;
		int sum = 0;

		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i].nHours * 3600 + v[i].nMinutes*60 + v[i].nSeconds;
		}
		hours = sum / 3600;
		minutes = (sum % 3600) / 60;
		seconds = sum - hours * 3600 - minutes * 60;
		return Time(hours, minutes, seconds);
	}

int main() {
	Time time(0, 0, 0);

	std::vector<Time> Times = time.getTimesFromString("23:59:59 09:32:22 04:25:48 12:00:00");
	Time Date = Time::sumTimes({ Time(14,14,14), Time(12,48,12), Time(24,24,24) });

	for (int i = 0; i < Times.size(); i++)
	{
		std::cout << Times[i] << std::endl;
	}
	
	std::cout << Date.hours() << ":" << Date.minutes() << ":" << Date.seconds() << std::endl;

}