/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 13:58:40 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 21:58:32 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"

class Hostname: public IMonitorModule
{
	public:
		~Hostname();
		Hostname();
		std::string	getName();
		std::string getHost(void);
		std::string getUsername();
		void	setHostUser();
		Hostname(Hostname const &);
		Hostname & operator=(Hostname const &);
	private:
		std::string _hostname;
		std::string _username;
};

#endif
