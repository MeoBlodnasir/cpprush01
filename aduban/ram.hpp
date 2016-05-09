/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:19:53 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:43:24 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"

class Ram: public IMonitorModule
{
	private:
		Ram & operator=(Ram const &);
		Ram(Ram const &);
	public:
		Ram();
		~Ram();
		std::string	getName();
		double total;
		double wired;
		double active;
		double inactive; 
		double free;
		void	setAll();
};

#endif
