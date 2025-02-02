#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;

# ifdef _WIN32
    const std::string NEWLINE = "\r\n";
# else
    const std::string NEWLINE = "\n";
# endif

class Contact {
private:
	string m_fName;
	string m_lName;
	string m_nickName;
	string m_phoneNo;
	string m_secret;

	class ToStringMode {
	private:
		int m_selection;
		int m_width;
		string m_terminator;
		string m_separator;

		ToStringMode();
		ToStringMode(const ToStringMode &other);
		ToStringMode &operator=(const ToStringMode &other);
	public:
		static const int F_NAME;
		static const int L_NAME;
		static const int NICK_NAME;
		static const int PHONE_NO;
		static const int SECRET;

		int getSelection() const;
		int getWidth() const;
		string getTerminator() const;
		string getSeparator() const;
		ToStringMode(int selection, int width, string terminator, string separator);
		~ToStringMode();
	};
	int processField(
		stringstream &ss
		, const string &field
		, const int &selector
		, int &selection
		, const ToStringMode &mode
	) const;

	Contact(
		string fName
		, string lName
		, string nickName
		, string phoneNo
		, string secret
	);
	Contact(const Contact &other);
public:
	Contact();
	~Contact();
	Contact &operator=(const Contact &other);
	Contact(istream &ifs, ostream &ofs);

	static const ToStringMode FLN_PIPE_10;
	static const ToStringMode FLNPS_SEP_LINES;

	string toString(const ToStringMode &mode) const;
};

#endif