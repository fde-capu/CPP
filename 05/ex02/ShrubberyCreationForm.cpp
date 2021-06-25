/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:25:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 21:24:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

std::string ShrubberyTreeArt(int width, int height)
{
	double noise_level = (rand() % 30) / 100.0;
	double stick_level = (rand() % 100) / 100.0;
	double wide_level = ((rand() % 10) + 5) / 100.0;
	int ok = 0;
	char tree[width][height];
	int trunk;
	int pos;
	double log_chance;
	int wide;
	int mid;
	while (!ok)
	{
		trunk = rand() % ((width / 10) + 3);
		pos = (rand() % ((width / 2) - trunk)) + width / 4;
		mid = pos + (trunk / 2);
		for (int w = 0; w < width; w++)
			if (w >= pos && w < pos + trunk)
				tree[w][0] = '*';
			else
				tree[w][0] = ' ';
		for (int h = 1; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				log_chance = 0;
				if (
						(tree[w][h - 1] == '*' && rand() % 7 > 0)
						|| (w + 1 < width	&& tree[w + 1][h - 1] == '*' && h > height / 10)
						|| (w - 1 > 0		&& tree[w - 1][h - 1] == '*' && h > height / 10)
						|| (w + 2 < width	&& tree[w + 2][h - 1] == '*' && h > height / 9)
						|| (w - 2 > 0		&& tree[w - 2][h - 1] == '*' && h > height / 9)
						|| (w + 3 < width	&& tree[w + 3][h - 1] == '*' && h > height / 8)
						|| (w - 3 > 0		&& tree[w - 3][h - 1] == '*' && h > height / 8)
						|| (w + 4 < width	&& tree[w + 4][h - 1] == '*' && h > height / 7)
						|| (w - 4 > 0		&& tree[w - 4][h - 1] == '*' && h > height / 7)
						|| (w + 5 < width	&& tree[w + 5][h - 1] == '*' && h > height / 6)
						|| (w - 5 > 0		&& tree[w - 5][h - 1] == '*' && h > height / 6)
						|| (w + 6 < width	&& tree[w + 6][h - 1] == '*' && h > height / 7)
						|| (w - 6 > 0		&& tree[w - 6][h - 1] == '*' && h > height / 7)
						|| (w + 7 < width	&& tree[w + 7][h - 1] == '*' && h > height / 8)
						|| (w - 7 > 0		&& tree[w - 7][h - 1] == '*' && h > height / 8)
				   )
					log_chance = 1;
				log_chance *= ((double)height - (double)h) / (double)height;
				wide = w <= mid ? mid - w : w - mid;
				wide++;
				log_chance /= ((double)wide / ((double)width / (1.0 / wide_level)));
				if (h < height / 10 && log_chance > 0)
					log_chance = 1;
				if (log_chance && rand() % 1000 <= log_chance * 1000)
					tree[w][h] = '*';
				else
					tree[w][h] = ' ';
			}
		}
		for (int h = 1; h < height; h++)
			for (int w = 0; w < width; w++)
				if (
						tree[w][h] == ' ' &&
						(
						 (tree[w][h - 1] == '*')
						 || (w + 1 < width	&& tree[w + 1][h - 0] == '*' && h > height / 7)
						 || (w - 1 > 0		&& tree[w - 1][h - 0] == '*' && h > height / 7)
						 || (w + 1 < width	&& tree[w + 1][h - 1] == '*' && h > height / 7)
						 || (w - 1 > 0		&& tree[w - 1][h - 1] == '*' && h > height / 7)
						)
						&& rand() % (int)(1.0 / stick_level) == 0
				   )
					tree[w][h] = rand() % 2 ? w < mid ? rand() % 2 ? '\\' : '`' : rand() % 2 ? '/' : ',' : '.';
		std::string noise("o@#|%\"O-~^\\/_${}[]:<>?;\'");
		for (int h = 1; h < height; h++)
			for (int w = 0; w < width; w++)
				if (tree[w][h] != ' ' && rand() % (int)(1.0 / noise_level) == 0)
					tree[w][h] = noise.at(rand() % noise.length());
		for (int w = 0; w < width; w++)
			if (tree[w][height - 1] != ' ')
				ok = 1;
	}
	std::stringstream ss;
	for (int h = height - 1; h >= 0; h--)
	{
		for (int w = 0; w < width; w++)
			ss << tree[w][h];
		ss << std::endl;
	}
	return ss.str();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string u_target)
: Form("ShrubberyCreationForm", 145, 137)
{
	deb("Created a ShrubberyForm");
	setTarget(u_target);
	return ;
}

void ShrubberyCreationForm::action() const
{
	deb("Executing Shrubbery");
	std::ofstream file;
	file.open(getTarget().c_str());
	file << ShrubberyTreeArt(64, 64);
	file.close();
	return ;
}
