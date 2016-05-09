/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwok.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:48:46 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:41:30 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP

# include "IMonitorModule.hpp"

class Network: public IMonitorModule
{
	private:
		Network & operator=(Network const &);
		Network(Network const &);
	public:
		Network();
		std::string	getName();
		~Network();
		u_int64_t totalibytes;
		u_int64_t totalobytes;
		std::string ipv4;
		std::string ipv6;
		void	setAll();
};

#endif
