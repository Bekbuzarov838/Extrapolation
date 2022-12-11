#pragma once
#include <iostream>
#include <vector>

const float ErrIncorrectAlpha = -1.0;

/*
���������� ������ ����������������� �����������.

@param[in] time_series ��������� ���.
@param[in] alpha ����������� ����������� ����� 0 � 1.
@param[in] s0 ������������������ ������ �������� S.

@return ���������� ��������.
*/
float exponential_smoothing(std::vector<double> x, std::vector<double> y, std::vector<double> x1, float alpha, float s0);



