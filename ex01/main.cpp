/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:08:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/08 08:00:31 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    uintptr_t uint;
    Data *orig_data = new Data();
    Data *new_data;
	// 
    orig_data->age = 21;
    orig_data->salary = 1337; // $
    orig_data->name = "Youssef Labrahmi";
    orig_data->mother_name = "Mama";
    orig_data->father_name = "Baba";
    orig_data->brother_name = "Khwadri";
    orig_data->sister_name = "Khwadria";
    orig_data->avg_1 = 1341.54;
    orig_data->avg_2 = 1342.53;
    orig_data->avg_3 = 1343.52;
    orig_data->avg_4 = 1344.51;
	// 
    uint = Serializer::serialize(orig_data);
    new_data = Serializer::deserialize(uint);
	// 
    std::cout << "Age:          " << new_data->age << std::endl;
    std::cout << "salary:       " << new_data->salary << std::endl;
    std::cout << "name:         " << new_data->name << std::endl;
    std::cout << "mother_name:  " << new_data->mother_name << std::endl;
    std::cout << "father_name:  " << new_data->father_name << std::endl;
    std::cout << "brother_name: " << new_data->brother_name << std::endl;
    std::cout << "sister_name:  " << new_data->sister_name << std::endl;
    std::cout << "avg_1:        " << new_data->avg_1 << std::endl;
    std::cout << "avg_2:        " << new_data->avg_2 << std::endl;
    std::cout << "avg_3:        " << new_data->avg_3 << std::endl;
    std::cout << "avg_4:        " << new_data->avg_4 << std::endl;
	// 
	delete orig_data;
    return 0;
}
