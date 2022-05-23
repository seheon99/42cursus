/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:04:11 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:44:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
public:
	Character(std::string);
	Character(Character const& other);
	virtual ~Character();

	Character&	operator=(Character const& other);

	virtual std::string const&	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);
protected:
	Character();
private:
	std::string					_name;
	int							_numInventory;
	static int const			_numInventoryMax = 4;
	AMateria*					_inventory[4];
};

#endif
