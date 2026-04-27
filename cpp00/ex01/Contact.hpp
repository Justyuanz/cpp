#ifndef CONTACT_HPP
# define CONTACT_HPP

#include<string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _dark_secret;
	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(const std::string &first_name);
		void		setLastName(const std::string &last_name);
		void		setNickName(const std::string &nick_name);
		void		setPhoneNumber(const std::string &phone_number);
		void		setDarkSecret(const std::string &dark_secret);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkSecret(void) const;
};

#endif
