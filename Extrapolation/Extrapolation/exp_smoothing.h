#pragma once
#include <iostream>
#include <list>

const float ErrIncorrectAlpha = -1.0;

/*
���������� ������ ����������������� �����������.

@param[in] time_series ��������� ���.
@param[in] alpha ����������� ����������� ����� 0 � 1.
@param[in] s0 ������������������ ������ �������� S.

@return ���������� ��������.
*/
float exponential_smoothing(std::list<float> time_series, float alpha, float s0) {
	if (alpha > 1 || alpha < 0) {
		// ���� �������� alpha ����� �� ���������, ������������ ������
		return ErrIncorrectAlpha;
	}

	float predict_value = s0;
	float fact_value;

	for (std::list<float>::iterator r = time_series.begin(); r != time_series.end(); r++) {
		fact_value = *r;
		predict_value = alpha * fact_value + (1 - alpha) * predict_value;
	}

	return predict_value;
}

int main()
{
	// �������� ��������
	std::list<float> ts = {  };
	float predict_value;

	// ������ ������ 
	predict_value = exponential_smoothing(ts, 1, 0);

	if (predict_value == ErrIncorrectAlpha) {
		std::cout << "Alpha must be between 0 and 1" << std::endl;
	}
	else {
		std::cout << "Predict value: " << predict_value << std::endl;
	}


	return 0;
}
