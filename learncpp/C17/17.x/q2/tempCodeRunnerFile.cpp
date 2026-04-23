
	else
	{
		m_gold -= itemCost;
		m_inventory[static_cast<size_t>(item)] += 1;
		std::cout << "You purchased a potion of " << Potion::names[static_cast<size_t>(item)] << " You have " << m_gold << " gold left. \n\n