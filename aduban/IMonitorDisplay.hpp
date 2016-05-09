/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 19:33:05 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:59:10 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
	public:
		IMonitorDisplay();
		~IMonitorDisplay();
		virtual void	init()=0;
	private:
		IMonitorDisplay(IMonitorDisplay const &);
		IMonitorDisplay & operator=(IMonitorDisplay const &);
};

#endif
