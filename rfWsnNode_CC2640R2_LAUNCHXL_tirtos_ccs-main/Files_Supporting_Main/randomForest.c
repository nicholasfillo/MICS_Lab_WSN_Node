#include <stdio.h>
#include <math.h>
#include "randomForest.h"
#include "Feature_Extraction.h"

// 0 = Pig is Drinking
// 1 = Pig is Eating
// 2 = Pig is Laying Down
// 3 = Pig is Standing
// 4 = Pig is Walking
// 5 = Unknown/Not Valid
int randomForest(Feature_Extraction* feature_extraction) {
    if (feature_extraction->accel_y.acc_y_std <= 0.04)
    {
	if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.07)
	{
		if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.33)
		{
			if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.21)
			{
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 2.89)
				{
					if (feature_extraction->accel_x.acc_x_absolut_energy <= 0.01)
					{
						return 3;
					}
					if (feature_extraction->accel_x.acc_x_absolut_energy >  0.01)
					{
						if (feature_extraction->accel_mag.acc_magnitude_mean <= 0.67)
						{
							return 4;
						}
						if (feature_extraction->accel_mag.acc_magnitude_mean >  0.67)
						{
							if (feature_extraction->gyro_x.gyro_x_IQR <= 0.00)
							{
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 0.06)
								{
									if (feature_extraction->accel_x.acc_x_time_series_complexity <= 0.12)
									{
										if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.00)
										{
											return 3;
										}
										if (feature_extraction->gyro_y.gyro_y_mean_square >  0.00)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_x.acc_x_time_series_complexity >  0.12)
									{
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.14)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.14)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  0.06)
								{
									if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 3.09)
									{
										if (feature_extraction->accel_y.acc_y_mean <= 0.16)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  0.16)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  3.09)
									{
										if (feature_extraction->accel_y.acc_y_median <= 0.01)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_median >  0.01)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_x.gyro_x_IQR >  0.00)
							{
								return 4;
							}
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  2.89)
				{
					if (feature_extraction->accel_x.acc_x_max <= 0.63)
					{
						return 3;
					}
					if (feature_extraction->accel_x.acc_x_max >  0.63)
					{
						return 2;
					}
				}
			}
			if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.21)
			{
				if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error <= 7.64)
				{
					if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 3.43)
					{
						if (feature_extraction->gyro_mag.gyro_magnitude_std <= 0.38)
						{
							if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 2.93)
							{
								return 2;
							}
							if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  2.93)
							{
								return 3;
							}
						}
						if (feature_extraction->gyro_mag.gyro_magnitude_std >  0.38)
						{
							return 2;
						}
					}
					if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  3.43)
					{
						if (feature_extraction->accel_z.acc_z_mean_square <= 0.38)
						{
							return 4;
						}
						if (feature_extraction->accel_z.acc_z_mean_square >  0.38)
						{
							return 3;
						}
					}
				}
				if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error >  7.64)
				{
					if (feature_extraction->accel_y.acc_y_IQR <= 0.02)
					{
						if (feature_extraction->gyro_z.gyro_z_std <= 0.91)
						{
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 17.61)
							{
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 0.06)
								{
									return 3;
								}
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  0.06)
								{
									return 4;
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  17.61)
							{
								if (feature_extraction->gyro_x.gyro_x_find_skewness <= -4.42)
								{
									return 4;
								}
								if (feature_extraction->gyro_x.gyro_x_find_skewness >  -4.42)
								{
									if (feature_extraction->accel_y.acc_y_median <= -1.89)
									{
										if (feature_extraction->accel_x.acc_x_max <= 0.03)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_max >  0.03)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_y.acc_y_median >  -1.89)
									{
										if (feature_extraction->accel_x.acc_x_min <= 1.46)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_min >  1.46)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_z.gyro_z_std >  0.91)
						{
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 5.40)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 14.52)
								{
									return 2;
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  14.52)
								{
									return 3;
								}
							}
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  5.40)
							{
								if (feature_extraction->accel_x.acc_x_absolut_energy <= 152.58)
								{
									return 2;
								}
								if (feature_extraction->accel_x.acc_x_absolut_energy >  152.58)
								{
									return 3;
								}
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_IQR >  0.02)
					{
						if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.22)
						{
							if (feature_extraction->accel_y.acc_y_find_skewness <= 1.34)
							{
								if (feature_extraction->accel_x.acc_x_std  <= 0.09)
								{
									if (feature_extraction->accel_y.acc_y_IQR <= 0.03)
									{
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 5.00)
										{
											return 3;
										}
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  5.00)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_y.acc_y_IQR >  0.03)
									{
										if (feature_extraction->accel_z.acc_z_min <= 0.92)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_min >  0.92)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_std  >  0.09)
								{
									if (feature_extraction->accel_z.acc_z_max <= 0.12)
									{
										return 2;
									}
									if (feature_extraction->accel_z.acc_z_max >  0.12)
									{
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 5.39)
										{
											return 2;
										}
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  5.39)
										{
											return 3;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_find_skewness >  1.34)
							{
								if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation <= 0.11)
								{
									return 3;
								}
								if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation >  0.11)
								{
									return 2;
								}
							}
						}
						if (feature_extraction->gyro_z.gyro_z_mean_square >  0.22)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis <= 0.60)
							{
								if (feature_extraction->accel_z.acc_z_mean  <= 0.68)
								{
									return 2;
								}
								if (feature_extraction->accel_z.acc_z_mean  >  0.68)
								{
									return 3;
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis >  0.60)
							{
								return 2;
							}
						}
					}
				}
			}
		}
		if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.33)
		{
			if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.03)
			{
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 1.20)
				{
					if (feature_extraction->accel_x.acc_x_time_series_complexity <= 0.18)
					{
						if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis <= 1.65)
						{
							if (feature_extraction->accel_y.acc_y_max <= -1.86)
							{
								if (feature_extraction->accel_z.acc_z_absolut_energy <= 156.68)
								{
									return 3;
								}
								if (feature_extraction->accel_z.acc_z_absolut_energy >  156.68)
								{
									return 2;
								}
							}
							if (feature_extraction->accel_y.acc_y_max >  -1.86)
							{
								return 2;
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis >  1.65)
						{
							if (feature_extraction->accel_y.acc_y_max <= -1.84)
							{
								return 3;
							}
							if (feature_extraction->accel_y.acc_y_max >  -1.84)
							{
								return 2;
							}
						}
					}
					if (feature_extraction->accel_x.acc_x_time_series_complexity >  0.18)
					{
						if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 0.27)
						{
							if (feature_extraction->accel_z.acc_z_median <= 0.98)
							{
								if (feature_extraction->accel_z.acc_z_find_kurtosis <= -1.21)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.00)
									{
										if (feature_extraction->accel_y.acc_y_absolut_energy <= 152.00)
										{
											return 3;
										}
										if (feature_extraction->accel_y.acc_y_absolut_energy >  152.00)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.00)
									{
										return 2;
									}
								}
								if (feature_extraction->accel_z.acc_z_find_kurtosis >  -1.21)
								{
									if (feature_extraction->accel_x.acc_x_absolut_energy <= 72.97)
									{
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 7.33)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  7.33)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolut_energy >  72.97)
									{
										if (feature_extraction->accel_mag.acc_magnitude_std <= 0.03)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_std >  0.03)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_median >  0.98)
							{
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 13.00)
								{
									return 2;
								}
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  13.00)
								{
									return 3;
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  0.27)
						{
							if (feature_extraction->accel_y.acc_y_max <= -1.82)
							{
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 0.00)
								{
									return 2;
								}
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  0.00)
								{
									return 3;
								}
							}
							if (feature_extraction->accel_y.acc_y_max >  -1.82)
							{
								return 2;
							}
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  1.20)
				{
					if (feature_extraction->accel_y.acc_y_euclidian_norm <= 2.44)
					{
						if (feature_extraction->gyro_z.gyro_z_IQR <= 0.08)
						{
							if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 3.42)
							{
								return 3;
							}
							if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  3.42)
							{
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 9.52)
								{
									if (feature_extraction->accel_z.acc_z_mean  <= 0.56)
									{
										return 3;
									}
									if (feature_extraction->accel_z.acc_z_mean  >  0.56)
									{
										return 2;
									}
								}
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  9.52)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 1.38)
									{
										return 2;
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean_square >  1.38)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 1.50)
										{
											return 3;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  1.50)
										{
											return 2;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_z.gyro_z_IQR >  0.08)
						{
							if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.04)
							{
								return 3;
							}
							if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.04)
							{
								return 2;
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_euclidian_norm >  2.44)
					{
						if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 0.48)
						{
							return 3;
						}
						if (feature_extraction->accel_mag.acc_magnitude_mean_square >  0.48)
						{
							if (feature_extraction->gyro_z.gyro_z_mean <= -0.46)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_IQR <= 0.70)
								{
									return 3;
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_IQR >  0.70)
								{
									if (feature_extraction->gyro_z.gyro_z_find_kurtosis <= 0.28)
									{
										return 3;
									}
									if (feature_extraction->gyro_z.gyro_z_find_kurtosis >  0.28)
									{
										return 2;
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_mean >  -0.46)
							{
								if (feature_extraction->accel_y.acc_y_max <= 0.72)
								{
									if (feature_extraction->accel_x.acc_x_absolut_energy <= 71.44)
									{
										return 2;
									}
									if (feature_extraction->accel_x.acc_x_absolut_energy >  71.44)
									{
										if (feature_extraction->accel_x.acc_x_find_kurtosis <= 2.91)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_find_kurtosis >  2.91)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_max >  0.72)
								{
									if (feature_extraction->gyro_y.gyro_y_find_skewness <= -1.13)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.58)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.58)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_find_skewness >  -1.13)
									{
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 2.28)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  2.28)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
			}
			if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.03)
			{
				if (feature_extraction->accel_y.acc_y_mean_square <= 1.40)
				{
					if (feature_extraction->accel_x.acc_x_min <= -0.45)
					{
						if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 2.84)
						{
							if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 22.90)
							{
								if (feature_extraction->gyro_x.gyro_x_median <= -0.61)
								{
									return 1;
								}
								if (feature_extraction->gyro_x.gyro_x_median >  -0.61)
								{
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 8.50)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.11)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.11)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  8.50)
									{
										return 2;
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  22.90)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 1.30)
								{
									return 3;
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_mean >  1.30)
								{
									return 2;
								}
							}
						}
						if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  2.84)
						{
							return 2;
						}
					}
					if (feature_extraction->accel_x.acc_x_min >  -0.45)
					{
						if (feature_extraction->gyro_y.gyro_y_IQR <= 0.00)
						{
							if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.14)
							{
								if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 0.44)
								{
									if (feature_extraction->accel_x.acc_x_median <= -0.01)
									{
										return 4;
									}
									if (feature_extraction->accel_x.acc_x_median >  -0.01)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_mean_square >  0.44)
								{
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.01)
									{
										if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.02)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean_square >  0.02)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.01)
									{
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.03)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.03)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_mean_square >  0.14)
							{
								if (feature_extraction->gyro_z.gyro_z_std <= 0.46)
								{
									if (feature_extraction->gyro_x.gyro_x_std <= 0.61)
									{
										if (feature_extraction->accel_z.acc_z_find_kurtosis <= 1.62)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_find_kurtosis >  1.62)
										{
											return 4;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_std >  0.61)
									{
										if (feature_extraction->accel_x.acc_x_median <= 0.63)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_median >  0.63)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_std >  0.46)
								{
									if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.04)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 1.98)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  1.98)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.04)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 3.29)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_square >  3.29)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_y.gyro_y_IQR >  0.00)
						{
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 105.76)
							{
								if (feature_extraction->accel_y.acc_y_max <= -0.12)
								{
									if (feature_extraction->gyro_y.gyro_y_find_skewness <= -0.80)
									{
										if (feature_extraction->gyro_y.gyro_y_min <= -2.01)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_min >  -2.01)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_find_skewness >  -0.80)
									{
										if (feature_extraction->gyro_z.gyro_z_IQR <= 1.48)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_IQR >  1.48)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_max >  -0.12)
								{
									if (feature_extraction->gyro_z.gyro_z_std <= 0.52)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 91.96)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  91.96)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_std >  0.52)
									{
										if (feature_extraction->gyro_y.gyro_y_min <= -1.36)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_min >  -1.36)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  105.76)
							{
								if (feature_extraction->accel_y.acc_y_std <= 0.02)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error <= 20.66)
									{
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 5.82)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  5.82)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error >  20.66)
									{
										if (feature_extraction->accel_z.acc_z_absolut_energy <= 21.89)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_absolut_energy >  21.89)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_std >  0.02)
								{
									if (feature_extraction->accel_y.acc_y_mean <= -0.49)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.72)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.72)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean >  -0.49)
									{
										if (feature_extraction->accel_y.acc_y_mean <= -0.28)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  -0.28)
										{
											return 2;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_y.acc_y_mean_square >  1.40)
				{
					if (feature_extraction->gyro_x.gyro_x_std <= 1.23)
					{
						return 2;
					}
					if (feature_extraction->gyro_x.gyro_x_std >  1.23)
					{
						if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 0.43)
						{
							return 2;
						}
						if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  0.43)
						{
							if (feature_extraction->accel_z.acc_z_find_skewness <= -0.16)
							{
								return 2;
							}
							if (feature_extraction->accel_z.acc_z_find_skewness >  -0.16)
							{
								if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= 0.14)
								{
									return 4;
								}
								if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  0.14)
								{
									return 1;
								}
							}
						}
					}
				}
			}
		}
	}
	if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.07)
	{
		if (feature_extraction->accel_x.acc_x_median <= -0.34)
		{
			if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 0.40)
			{
				if (feature_extraction->accel_mag.acc_magnitude_min <= 1.85)
				{
					if (feature_extraction->accel_x.acc_x_IQR <= 0.06)
					{
						return 2;
					}
					if (feature_extraction->accel_x.acc_x_IQR >  0.06)
					{
						if (feature_extraction->accel_y.acc_y_median <= -0.61)
						{
							return 2;
						}
						if (feature_extraction->accel_y.acc_y_median >  -0.61)
						{
							if (feature_extraction->accel_mag.acc_magnitude_median <= 1.45)
							{
								if (feature_extraction->accel_x.acc_x_median <= -0.40)
								{
									return 3;
								}
								if (feature_extraction->accel_x.acc_x_median >  -0.40)
								{
									if (feature_extraction->accel_y.acc_y_find_kurtosis <= -0.46)
									{
										return 2;
									}
									if (feature_extraction->accel_y.acc_y_find_kurtosis >  -0.46)
									{
										return 3;
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_median >  1.45)
							{
								if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.81)
								{
									return 1;
								}
								if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.81)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_max <= 3.57)
									{
										return 3;
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_max >  3.57)
									{
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 6.50)
										{
											return 3;
										}
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  6.50)
										{
											return 1;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_min >  1.85)
				{
					return 2;
				}
			}
			if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  0.40)
			{
				if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 1.81)
				{
					if (feature_extraction->accel_z.acc_z_euclidian_norm <= 3.56)
					{
						if (feature_extraction->gyro_x.gyro_x_std <= 1.24)
						{
							if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 0.28)
							{
								return 2;
							}
							if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  0.28)
							{
								return 1;
							}
						}
						if (feature_extraction->gyro_x.gyro_x_std >  1.24)
						{
							if (feature_extraction->gyro_y.gyro_y_find_skewness <= 1.17)
							{
								return 3;
							}
							if (feature_extraction->gyro_y.gyro_y_find_skewness >  1.17)
							{
								return 1;
							}
						}
					}
					if (feature_extraction->accel_z.acc_z_euclidian_norm >  3.56)
					{
						if (feature_extraction->gyro_y.gyro_y_find_skewness <= 1.85)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 18.16)
							{
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 5.38)
								{
									return 2;
								}
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  5.38)
								{
									return 1;
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  18.16)
							{
								return 3;
							}
						}
						if (feature_extraction->gyro_y.gyro_y_find_skewness >  1.85)
						{
							return 1;
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  1.81)
				{
					if (feature_extraction->gyro_x.gyro_x_std <= 1.44)
					{
						if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 13.00)
						{
							return 1;
						}
						if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  13.00)
						{
							return 2;
						}
					}
					if (feature_extraction->gyro_x.gyro_x_std >  1.44)
					{
						return 3;
					}
				}
			}
		}
		if (feature_extraction->accel_x.acc_x_median >  -0.34)
		{
			if (feature_extraction->gyro_x.gyro_x_median <= 0.36)
			{
				if (feature_extraction->accel_y.acc_y_absolut_energy <= 56.48)
				{
					if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 140.24)
					{
						if (feature_extraction->gyro_y.gyro_y_mean <= -0.03)
						{
							if (feature_extraction->accel_z.acc_z_min <= 0.72)
							{
								if (feature_extraction->accel_z.acc_z_time_series_complexity <= 0.50)
								{
									return 3;
								}
								if (feature_extraction->accel_z.acc_z_time_series_complexity >  0.50)
								{
									if (feature_extraction->accel_z.acc_z_min <= 0.45)
									{
										return 2;
									}
									if (feature_extraction->accel_z.acc_z_min >  0.45)
									{
										return 4;
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_min >  0.72)
							{
								return 2;
							}
						}
						if (feature_extraction->gyro_y.gyro_y_mean >  -0.03)
						{
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 7.76)
							{
								if (feature_extraction->accel_y.acc_y_max <= -0.32)
								{
									if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= -0.33)
									{
										return 2;
									}
									if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  -0.33)
									{
										return 4;
									}
								}
								if (feature_extraction->accel_y.acc_y_max >  -0.32)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 0.27)
									{
										return 2;
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  0.27)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 3.78)
										{
											return 3;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  3.78)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  7.76)
							{
								if (feature_extraction->gyro_z.gyro_z_absolut_energy <= 45.63)
								{
									return 2;
								}
								if (feature_extraction->gyro_z.gyro_z_absolut_energy >  45.63)
								{
									return 4;
								}
							}
						}
					}
					if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  140.24)
					{
						if (feature_extraction->accel_z.acc_z_IQR <= 0.11)
						{
							if (feature_extraction->accel_x.acc_x_max <= 1.06)
							{
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.02)
								{
									return 2;
								}
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.02)
								{
									if (feature_extraction->accel_y.acc_y_median <= -0.64)
									{
										return 2;
									}
									if (feature_extraction->accel_y.acc_y_median >  -0.64)
									{
										return 3;
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_max >  1.06)
							{
								if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 7.94)
								{
									return 4;
								}
								if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  7.94)
								{
									if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 38.09)
									{
										if (feature_extraction->accel_y.acc_y_std <= 0.03)
										{
											return 1;
										}
										if (feature_extraction->accel_y.acc_y_std >  0.03)
										{
											return 2;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  38.09)
									{
										return 0;
									}
								}
							}
						}
						if (feature_extraction->accel_z.acc_z_IQR >  0.11)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 29.47)
							{
								return 2;
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  29.47)
							{
								return 0;
							}
						}
					}
				}
				if (feature_extraction->accel_y.acc_y_absolut_energy >  56.48)
				{
					return 2;
				}
			}
			if (feature_extraction->gyro_x.gyro_x_median >  0.36)
			{
				if (feature_extraction->gyro_x.gyro_x_min <= -1.11)
				{
					if (feature_extraction->gyro_y.gyro_y_IQR <= 0.00)
					{
						if (feature_extraction->gyro_x.gyro_x_min <= -2.49)
						{
							if (feature_extraction->accel_x.acc_x_median <= 1.65)
							{
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 37.34)
								{
									if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.18)
									{
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis <= 12.49)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis >  12.49)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_mean_square >  0.18)
									{
										if (feature_extraction->accel_mag.acc_magnitude_median <= 0.90)
										{
											return 3;
										}
										if (feature_extraction->accel_mag.acc_magnitude_median >  0.90)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  37.34)
								{
									if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.01)
									{
										if (feature_extraction->accel_y.acc_y_IQR <= 0.04)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_IQR >  0.04)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_mean_square >  0.01)
									{
										return 3;
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_median >  1.65)
							{
								if (feature_extraction->accel_z.acc_z_euclidian_norm <= 4.32)
								{
									return 3;
								}
								if (feature_extraction->accel_z.acc_z_euclidian_norm >  4.32)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 3.65)
									{
										return 3;
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean_square >  3.65)
									{
										return 2;
									}
								}
							}
						}
						if (feature_extraction->gyro_x.gyro_x_min >  -2.49)
						{
							return 3;
						}
					}
					if (feature_extraction->gyro_y.gyro_y_IQR >  0.00)
					{
						if (feature_extraction->accel_z.acc_z_max <= 0.62)
						{
							if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= 1.61)
							{
								return 2;
							}
							if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  1.61)
							{
								if (feature_extraction->accel_x.acc_x_mean_square <= 2.99)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation <= 0.53)
									{
										return 4;
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation >  0.53)
									{
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 0.82)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  0.82)
										{
											return 3;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_mean_square >  2.99)
								{
									if (feature_extraction->gyro_z.gyro_z_mean <= -0.36)
									{
										return 3;
									}
									if (feature_extraction->gyro_z.gyro_z_mean >  -0.36)
									{
										return 2;
									}
								}
							}
						}
						if (feature_extraction->accel_z.acc_z_max >  0.62)
						{
							if (feature_extraction->gyro_y.gyro_y_IQR <= 0.33)
							{
								if (feature_extraction->accel_z.acc_z_time_series_complexity <= 0.78)
								{
									if (feature_extraction->gyro_x.gyro_x_find_skewness <= -1.63)
									{
										if (feature_extraction->accel_x.acc_x_mean <= 0.73)
										{
											return 3;
										}
										if (feature_extraction->accel_x.acc_x_mean >  0.73)
										{
											return 2;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_find_skewness >  -1.63)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_z.acc_z_time_series_complexity >  0.78)
								{
									return 2;
								}
							}
							if (feature_extraction->gyro_y.gyro_y_IQR >  0.33)
							{
								if (feature_extraction->accel_mag.acc_magnitude_max <= 1.62)
								{
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.03)
									{
										if (feature_extraction->accel_y.acc_y_max <= 0.25)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_max >  0.25)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.03)
									{
										if (feature_extraction->accel_x.acc_x_IQR <= 0.11)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_IQR >  0.11)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_max >  1.62)
								{
									if (feature_extraction->gyro_y.gyro_y_std <= 0.65)
									{
										if (feature_extraction->accel_y.acc_y_min <= -0.47)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  -0.47)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_std >  0.65)
									{
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 7.39)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  7.39)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->gyro_x.gyro_x_min >  -1.11)
				{
					if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.02)
					{
						if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.04)
						{
							if (feature_extraction->gyro_x.gyro_x_find_skewness <= 0.27)
							{
								if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= 0.23)
								{
									return 2;
								}
								if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  0.23)
								{
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm <= 4.29)
									{
										return 3;
									}
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm >  4.29)
									{
										return 2;
									}
								}
							}
							if (feature_extraction->gyro_x.gyro_x_find_skewness >  0.27)
							{
								if (feature_extraction->gyro_z.gyro_z_std <= 1.11)
								{
									return 2;
								}
								if (feature_extraction->gyro_z.gyro_z_std >  1.11)
								{
									if (feature_extraction->accel_y.acc_y_mean <= 0.35)
									{
										return 3;
									}
									if (feature_extraction->accel_y.acc_y_mean >  0.35)
									{
										return 2;
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.04)
						{
							return 3;
						}
					}
					if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.02)
					{
						if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 1.86)
						{
							if (feature_extraction->accel_y.acc_y_median <= 0.19)
							{
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 3.83)
								{
									if (feature_extraction->accel_z.acc_z_euclidian_norm <= 6.47)
									{
										if (feature_extraction->accel_y.acc_y_absolut_energy <= 0.56)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_absolut_energy >  0.56)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_z.acc_z_euclidian_norm >  6.47)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  3.83)
								{
									if (feature_extraction->gyro_z.gyro_z_min <= -1.11)
									{
										if (feature_extraction->accel_mag.acc_magnitude_median <= 1.18)
										{
											return 1;
										}
										if (feature_extraction->accel_mag.acc_magnitude_median >  1.18)
										{
											return 2;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_min >  -1.11)
									{
										return 3;
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_median >  0.19)
							{
								if (feature_extraction->gyro_x.gyro_x_std <= 0.51)
								{
									return 2;
								}
								if (feature_extraction->gyro_x.gyro_x_std >  0.51)
								{
									return 3;
								}
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_mean_square >  1.86)
						{
							if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.62)
							{
								if (feature_extraction->accel_y.acc_y_mean_square <= 0.00)
								{
									return 3;
								}
								if (feature_extraction->accel_y.acc_y_mean_square >  0.00)
								{
									if (feature_extraction->accel_x.acc_x_median <= 1.57)
									{
										return 2;
									}
									if (feature_extraction->accel_x.acc_x_median >  1.57)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_square <= 0.01)
										{
											return 4;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_square >  0.01)
										{
											return 2;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.62)
							{
								return 3;
							}
						}
					}
				}
			}
		}
	}
}
if (feature_extraction->accel_y.acc_y_std >  0.04)
{
	if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.21)
	{
		if (feature_extraction->accel_x.acc_x_median <= -0.54)
		{
			if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 0.00)
			{
				if (feature_extraction->accel_y.acc_y_time_series_complexity <= 1.43)
				{
					if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 7.88)
					{
						if (feature_extraction->accel_x.acc_x_mean_square <= 2.39)
						{
							if (feature_extraction->gyro_y.gyro_y_std <= 1.05)
							{
								if (feature_extraction->accel_y.acc_y_mean_square <= 1.53)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.37)
									{
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 1.44)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  1.44)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.37)
									{
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 10.57)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  10.57)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean_square >  1.53)
								{
									return 2;
								}
							}
							if (feature_extraction->gyro_y.gyro_y_std >  1.05)
							{
								if (feature_extraction->accel_y.acc_y_euclidian_norm <= 6.11)
								{
									if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 73.72)
									{
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 0.00)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  0.00)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  73.72)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.70)
										{
											return 1;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.70)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_euclidian_norm >  6.11)
								{
									return 2;
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_mean_square >  2.39)
						{
							if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 7.38)
							{
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 4.84)
								{
									if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation <= 1.00)
									{
										if (feature_extraction->accel_x.acc_x_min <= -2.28)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_min >  -2.28)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation >  1.00)
									{
										return 1;
									}
								}
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  4.84)
								{
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.91)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 140.66)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  140.66)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.91)
									{
										if (feature_extraction->accel_y.acc_y_euclidian_norm <= 1.51)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_euclidian_norm >  1.51)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  7.38)
							{
								if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.81)
								{
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm <= 11.23)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 26.05)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  26.05)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm >  11.23)
									{
										if (feature_extraction->accel_x.acc_x_max <= -1.03)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_max >  -1.03)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.81)
								{
									if (feature_extraction->gyro_z.gyro_z_std <= 0.71)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error <= 19.27)
										{
											return 1;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error >  19.27)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_std >  0.71)
									{
										if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.25)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.25)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  7.88)
					{
						if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 8.03)
						{
							if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 12.91)
							{
								if (feature_extraction->accel_x.acc_x_max <= 0.00)
								{
									if (feature_extraction->accel_x.acc_x_std  <= 0.44)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 9.99)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  9.99)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_std  >  0.44)
									{
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 8.51)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  8.51)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_max >  0.00)
								{
									if (feature_extraction->accel_y.acc_y_mean <= -0.29)
									{
										return 0;
									}
									if (feature_extraction->accel_y.acc_y_mean >  -0.29)
									{
										return 3;
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  12.91)
							{
								if (feature_extraction->accel_x.acc_x_absolut_energy <= 148.34)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 4.22)
									{
										if (feature_extraction->gyro_z.gyro_z_find_skewness <= -0.45)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_skewness >  -0.45)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  4.22)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 16.96)
										{
											return 3;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  16.96)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_absolut_energy >  148.34)
								{
									if (feature_extraction->accel_x.acc_x_find_kurtosis <= 4.22)
									{
										if (feature_extraction->accel_x.acc_x_euclidian_norm <= 12.18)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_euclidian_norm >  12.18)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_find_kurtosis >  4.22)
									{
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 9.01)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  9.01)
										{
											return 1;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  8.03)
						{
							if (feature_extraction->accel_z.acc_z_IQR <= 0.09)
							{
								if (feature_extraction->gyro_x.gyro_x_find_skewness <= -0.32)
								{
									return 1;
								}
								if (feature_extraction->gyro_x.gyro_x_find_skewness >  -0.32)
								{
									return 3;
								}
							}
							if (feature_extraction->accel_z.acc_z_IQR >  0.09)
							{
								if (feature_extraction->accel_x.acc_x_IQR <= 0.80)
								{
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.14)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.22)
										{
											return 3;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.22)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.14)
									{
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 2.79)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  2.79)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_IQR >  0.80)
								{
									if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 8.22)
									{
										return 3;
									}
									if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  8.22)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.14)
										{
											return 1;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.14)
										{
											return 2;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_y.acc_y_time_series_complexity >  1.43)
				{
					if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity <= 4.03)
					{
						if (feature_extraction->gyro_x.gyro_x_median <= 0.36)
						{
							if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 4.06)
							{
								if (feature_extraction->gyro_y.gyro_y_IQR <= 0.57)
								{
									if (feature_extraction->gyro_z.gyro_z_std <= 1.19)
									{
										return 3;
									}
									if (feature_extraction->gyro_z.gyro_z_std >  1.19)
									{
										return 1;
									}
								}
								if (feature_extraction->gyro_y.gyro_y_IQR >  0.57)
								{
									if (feature_extraction->gyro_z.gyro_z_find_skewness <= -0.59)
									{
										if (feature_extraction->accel_y.acc_y_find_skewness <= -2.58)
										{
											return 3;
										}
										if (feature_extraction->accel_y.acc_y_find_skewness >  -2.58)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_find_skewness >  -0.59)
									{
										if (feature_extraction->accel_x.acc_x_median <= -1.22)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  -1.22)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  4.06)
							{
								if (feature_extraction->gyro_x.gyro_x_find_kurtosis <= -1.13)
								{
									if (feature_extraction->gyro_y.gyro_y_std <= 1.12)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 0.23)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  0.23)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_std >  1.12)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_square <= 4.95)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_square >  4.95)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_find_kurtosis >  -1.13)
								{
									if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 15.96)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 3.00)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  3.00)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  15.96)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.17)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.17)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_x.gyro_x_median >  0.36)
						{
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 7.95)
							{
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 11.43)
								{
									if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 10.46)
									{
										if (feature_extraction->accel_y.acc_y_min <= -0.52)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  -0.52)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  10.46)
									{
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 8.44)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  8.44)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  11.43)
								{
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 7.00)
									{
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 4.58)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  4.58)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  7.00)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis <= -0.73)
										{
											return 4;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis >  -0.73)
										{
											return 3;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  7.95)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_median <= 2.78)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 1.52)
									{
										if (feature_extraction->accel_x.acc_x_std  <= 0.31)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_std  >  0.31)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean >  1.52)
									{
										if (feature_extraction->accel_x.acc_x_std  <= 0.57)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_std  >  0.57)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_median >  2.78)
								{
									if (feature_extraction->accel_x.acc_x_std  <= 0.27)
									{
										return 1;
									}
									if (feature_extraction->accel_x.acc_x_std  >  0.27)
									{
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 12.52)
										{
											return 3;
										}
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  12.52)
										{
											return 4;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity >  4.03)
					{
						if (feature_extraction->gyro_y.gyro_y_std <= 1.05)
						{
							if (feature_extraction->accel_x.acc_x_mean <= -1.15)
							{
								if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 9.10)
								{
									if (feature_extraction->accel_z.acc_z_max <= 0.54)
									{
										if (feature_extraction->gyro_x.gyro_x_mean <= -1.13)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_mean >  -1.13)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_max >  0.54)
									{
										if (feature_extraction->accel_x.acc_x_time_series_complexity <= 1.66)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_time_series_complexity >  1.66)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  9.10)
								{
									if (feature_extraction->accel_z.acc_z_mean_square <= 0.05)
									{
										return 1;
									}
									if (feature_extraction->accel_z.acc_z_mean_square >  0.05)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 8.89)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  8.89)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean >  -1.15)
							{
								if (feature_extraction->gyro_z.gyro_z_median <= 0.10)
								{
									if (feature_extraction->accel_y.acc_y_mean_square <= 0.18)
									{
										if (feature_extraction->accel_x.acc_x_IQR <= 0.86)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_IQR >  0.86)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_square >  0.18)
									{
										if (feature_extraction->accel_x.acc_x_mean_square <= 1.00)
										{
											return 1;
										}
										if (feature_extraction->accel_x.acc_x_mean_square >  1.00)
										{
											return 2;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_median >  0.10)
								{
									if (feature_extraction->accel_z.acc_z_mean  <= 0.59)
									{
										if (feature_extraction->accel_y.acc_y_euclidian_norm <= 1.96)
										{
											return 3;
										}
										if (feature_extraction->accel_y.acc_y_euclidian_norm >  1.96)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean  >  0.59)
									{
										return 1;
									}
								}
							}
						}
						if (feature_extraction->gyro_y.gyro_y_std >  1.05)
						{
							if (feature_extraction->gyro_z.gyro_z_min <= -1.80)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_IQR <= 1.15)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 17.12)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.01)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.01)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  17.12)
									{
										if (feature_extraction->gyro_x.gyro_x_IQR <= 2.04)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_IQR >  2.04)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_IQR >  1.15)
								{
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 5.66)
									{
										if (feature_extraction->accel_y.acc_y_mean_square <= 0.05)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_square >  0.05)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  5.66)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_max <= 3.27)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_max >  3.27)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_min >  -1.80)
							{
								if (feature_extraction->gyro_y.gyro_y_max <= 2.58)
								{
									if (feature_extraction->gyro_z.gyro_z_median <= 0.92)
									{
										if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm <= 9.77)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm >  9.77)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_median >  0.92)
									{
										return 1;
									}
								}
								if (feature_extraction->gyro_y.gyro_y_max >  2.58)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.48)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity <= 6.28)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity >  6.28)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.48)
									{
										if (feature_extraction->accel_z.acc_z_absolut_energy <= 6.18)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolut_energy >  6.18)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
			}
			if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  0.00)
			{
				if (feature_extraction->accel_x.acc_x_max <= 0.01)
				{
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 13.28)
					{
						if (feature_extraction->accel_y.acc_y_IQR <= 0.19)
						{
							if (feature_extraction->gyro_y.gyro_y_IQR <= 1.93)
							{
								if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= -1.02)
								{
									return 4;
								}
								if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  -1.02)
								{
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 11.52)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 5.45)
										{
											return 4;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  5.45)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  11.52)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 1.41)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  1.41)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_IQR >  1.93)
							{
								if (feature_extraction->accel_y.acc_y_euclidian_norm <= 0.85)
								{
									if (feature_extraction->gyro_y.gyro_y_min <= -2.66)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 3.74)
										{
											return 4;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  3.74)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_min >  -2.66)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_y.acc_y_euclidian_norm >  0.85)
								{
									if (feature_extraction->accel_mag.acc_magnitude_std <= 0.50)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 63.07)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  63.07)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_std >  0.50)
									{
										if (feature_extraction->accel_x.acc_x_find_skewness <= 0.17)
										{
											return 3;
										}
										if (feature_extraction->accel_x.acc_x_find_skewness >  0.17)
										{
											return 4;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_IQR >  0.19)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_mean_square <= 6.68)
							{
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 8.01)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean <= 1.80)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.79)
										{
											return 3;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.79)
										{
											return 4;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean >  1.80)
									{
										if (feature_extraction->accel_x.acc_x_find_skewness <= 1.64)
										{
											return 4;
										}
										if (feature_extraction->accel_x.acc_x_find_skewness >  1.64)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  8.01)
								{
									if (feature_extraction->accel_y.acc_y_mean_square <= 0.05)
									{
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 32.34)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  32.34)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_square >  0.05)
									{
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 19.10)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  19.10)
										{
											return 4;
										}
									}
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_mean_square >  6.68)
							{
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.17)
								{
									return 3;
								}
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.17)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 19.41)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_square <= 6.83)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_square >  6.83)
										{
											return 4;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  19.41)
									{
										return 3;
									}
								}
							}
						}
					}
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  13.28)
					{
						if (feature_extraction->accel_mag.acc_magnitude_max <= 2.27)
						{
							if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 14.81)
							{
								return 3;
							}
							if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  14.81)
							{
								return 4;
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_max >  2.27)
						{
							if (feature_extraction->accel_y.acc_y_min <= -0.84)
							{
								if (feature_extraction->gyro_x.gyro_x_min <= -2.23)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 1.78)
									{
										return 4;
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean_square >  1.78)
									{
										return 3;
									}
								}
								if (feature_extraction->gyro_x.gyro_x_min >  -2.23)
								{
									return 4;
								}
							}
							if (feature_extraction->accel_y.acc_y_min >  -0.84)
							{
								if (feature_extraction->accel_x.acc_x_mean_square <= 1.99)
								{
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.38)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 45.66)
										{
											return 3;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  45.66)
										{
											return 4;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.38)
									{
										if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= -0.16)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  -0.16)
										{
											return 3;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_mean_square >  1.99)
								{
									if (feature_extraction->gyro_z.gyro_z_std <= 0.38)
									{
										return 3;
									}
									if (feature_extraction->gyro_z.gyro_z_std >  0.38)
									{
										if (feature_extraction->gyro_z.gyro_z_IQR <= 2.17)
										{
											return 4;
										}
										if (feature_extraction->gyro_z.gyro_z_IQR >  2.17)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_x.acc_x_max >  0.01)
				{
					if (feature_extraction->accel_y.acc_y_min <= -0.22)
					{
						if (feature_extraction->accel_y.acc_y_absolut_energy <= 1.78)
						{
							if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.40)
							{
								if (feature_extraction->accel_z.acc_z_time_series_complexity <= 1.21)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 204.87)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.75)
										{
											return 1;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.75)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  204.87)
									{
										return 1;
									}
								}
								if (feature_extraction->accel_z.acc_z_time_series_complexity >  1.21)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 2.26)
									{
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.37)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.37)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean_square >  2.26)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.13)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.13)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.40)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_median <= 1.77)
								{
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 8.72)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.21)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.21)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  8.72)
									{
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 6.52)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  6.52)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_median >  1.77)
								{
									if (feature_extraction->accel_z.acc_z_euclidian_norm <= 3.36)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 35.08)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  35.08)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_euclidian_norm >  3.36)
									{
										if (feature_extraction->gyro_y.gyro_y_mean <= 0.38)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean >  0.38)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_absolut_energy >  1.78)
						{
							if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= 0.15)
							{
								if (feature_extraction->gyro_z.gyro_z_min <= -1.81)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.17)
									{
										if (feature_extraction->accel_z.acc_z_max <= 0.34)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_max >  0.34)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.17)
									{
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 1.99)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  1.99)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_min >  -1.81)
								{
									if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 81.96)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 12.59)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  12.59)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  81.96)
									{
										if (feature_extraction->gyro_x.gyro_x_absolut_energy <= 39.92)
										{
											return 0;
										}
										if (feature_extraction->gyro_x.gyro_x_absolut_energy >  39.92)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  0.15)
							{
								if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 4.43)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 16.49)
									{
										if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 8.27)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  8.27)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  16.49)
									{
										if (feature_extraction->gyro_z.gyro_z_absolut_energy <= 25.38)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolut_energy >  25.38)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  4.43)
								{
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 8.22)
									{
										if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis <= 1.44)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis >  1.44)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  8.22)
									{
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 4.97)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  4.97)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_min >  -0.22)
					{
						if (feature_extraction->accel_mag.acc_magnitude_min <= 0.46)
						{
							if (feature_extraction->accel_x.acc_x_find_kurtosis <= -0.88)
							{
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 40.30)
								{
									if (feature_extraction->gyro_x.gyro_x_std <= 1.24)
									{
										if (feature_extraction->accel_z.acc_z_find_skewness <= 0.12)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_skewness >  0.12)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_std >  1.24)
									{
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 5.76)
										{
											return 3;
										}
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  5.76)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  40.30)
								{
									return 1;
								}
							}
							if (feature_extraction->accel_x.acc_x_find_kurtosis >  -0.88)
							{
								if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.22)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.78)
									{
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 6.59)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  6.59)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.78)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.22)
								{
									if (feature_extraction->accel_z.acc_z_max <= 1.76)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity <= 3.01)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity >  3.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_max >  1.76)
									{
										if (feature_extraction->accel_x.acc_x_median <= -1.35)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  -1.35)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_min >  0.46)
						{
							if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 1.49)
							{
								if (feature_extraction->accel_mag.acc_magnitude_max <= 2.26)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.29)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 13.40)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  13.40)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.29)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.20)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.20)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_max >  2.26)
								{
									return 1;
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  1.49)
							{
								if (feature_extraction->accel_x.acc_x_find_skewness <= 0.20)
								{
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 8.92)
									{
										if (feature_extraction->gyro_z.gyro_z_IQR <= 2.00)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_IQR >  2.00)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  8.92)
									{
										if (feature_extraction->accel_z.acc_z_IQR <= 0.45)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_IQR >  0.45)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_find_skewness >  0.20)
								{
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 13.00)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 12.04)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  12.04)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  13.00)
									{
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 0.94)
										{
											return 3;
										}
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  0.94)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (feature_extraction->accel_x.acc_x_median >  -0.54)
		{
			if (feature_extraction->accel_x.acc_x_median <= 0.61)
			{
				if (feature_extraction->accel_y.acc_y_absolut_energy <= 31.52)
				{
					if (feature_extraction->accel_x.acc_x_min <= -0.45)
					{
						if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 11.34)
						{
							if (feature_extraction->accel_y.acc_y_mean_square <= 0.00)
							{
								if (feature_extraction->gyro_y.gyro_y_std <= 0.92)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 2.80)
									{
										return 2;
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  2.80)
									{
										if (feature_extraction->accel_mag.acc_magnitude_max <= 1.23)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_max >  1.23)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_std >  0.92)
								{
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 1.10)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.18)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.18)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  1.10)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 1.83)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  1.83)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_mean_square >  0.00)
							{
								if (feature_extraction->accel_y.acc_y_std <= 0.10)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 8.23)
									{
										if (feature_extraction->accel_y.acc_y_min <= 0.48)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  0.48)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  8.23)
									{
										if (feature_extraction->accel_z.acc_z_euclidian_norm <= 4.64)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_euclidian_norm >  4.64)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_std >  0.10)
								{
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 7.03)
									{
										if (feature_extraction->accel_y.acc_y_min <= 0.28)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  0.28)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  7.03)
									{
										if (feature_extraction->accel_mag.acc_magnitude_min <= 0.88)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_min >  0.88)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  11.34)
						{
							if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 12.13)
							{
								if (feature_extraction->accel_y.acc_y_time_series_complexity <= 1.08)
								{
									if (feature_extraction->accel_x.acc_x_median <= -0.23)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 11.75)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  11.75)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_median >  -0.23)
									{
										if (feature_extraction->accel_y.acc_y_mean <= -0.41)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  -0.41)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_time_series_complexity >  1.08)
								{
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 0.00)
									{
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 11.71)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  11.71)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  0.00)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 1.07)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_square >  1.07)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  12.13)
							{
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 7.68)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 9.31)
									{
										if (feature_extraction->accel_y.acc_y_median <= -0.04)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_median >  -0.04)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  9.31)
									{
										if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 19.89)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  19.89)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  7.68)
								{
									if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error <= 54.66)
									{
										if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.24)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_mean_square >  0.24)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error >  54.66)
									{
										if (feature_extraction->accel_z.acc_z_std <= 0.40)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_std >  0.40)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_x.acc_x_min >  -0.45)
					{
						if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 31.00)
						{
							if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 0.37)
							{
								if (feature_extraction->accel_z.acc_z_absolut_energy <= 37.19)
								{
									if (feature_extraction->accel_y.acc_y_min <= -0.61)
									{
										if (feature_extraction->gyro_z.gyro_z_median <= -0.29)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_median >  -0.29)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_y.acc_y_min >  -0.61)
									{
										if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 0.25)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  0.25)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_absolut_energy >  37.19)
								{
									if (feature_extraction->accel_x.acc_x_min <= 0.19)
									{
										if (feature_extraction->accel_x.acc_x_mean_square <= 0.01)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_mean_square >  0.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_min >  0.19)
									{
										if (feature_extraction->accel_mag.acc_magnitude_std <= 0.05)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_std >  0.05)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  0.37)
							{
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 4.58)
								{
									if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 8.00)
									{
										if (feature_extraction->accel_y.acc_y_min <= -0.46)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  -0.46)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  8.00)
									{
										if (feature_extraction->accel_y.acc_y_absolut_energy <= 7.87)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_absolut_energy >  7.87)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  4.58)
								{
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 9.95)
									{
										if (feature_extraction->gyro_y.gyro_y_mean <= -0.23)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean >  -0.23)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  9.95)
									{
										if (feature_extraction->accel_z.acc_z_absolut_energy <= 13.21)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolut_energy >  13.21)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  31.00)
						{
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 44.19)
							{
								if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.12)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 28.58)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 11.07)
										{
											return 2;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  11.07)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  28.58)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_square <= 0.11)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_square >  0.11)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.12)
								{
									if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 9.03)
									{
										if (feature_extraction->gyro_y.gyro_y_median <= -0.06)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_median >  -0.06)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  9.03)
									{
										if (feature_extraction->accel_x.acc_x_find_kurtosis <= -0.21)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_find_kurtosis >  -0.21)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  44.19)
							{
								if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 0.72)
								{
									if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 10.97)
									{
										if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation <= 0.98)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation >  0.98)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  10.97)
									{
										if (feature_extraction->gyro_x.gyro_x_find_skewness <= 0.01)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_find_skewness >  0.01)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  0.72)
								{
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 6.61)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 27.75)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  27.75)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  6.61)
									{
										if (feature_extraction->accel_x.acc_x_euclidian_norm <= 4.72)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_euclidian_norm >  4.72)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_y.acc_y_absolut_energy >  31.52)
				{
					if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.24)
					{
						if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 1.00)
						{
							if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 1.94)
							{
								if (feature_extraction->accel_z.acc_z_median <= 0.28)
								{
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.06)
									{
										return 2;
									}
									if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.06)
									{
										if (feature_extraction->accel_y.acc_y_max <= -1.64)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_max >  -1.64)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_median >  0.28)
								{
									if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation <= 0.43)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean <= 1.14)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean >  1.14)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation >  0.43)
									{
										if (feature_extraction->accel_mag.acc_magnitude_min <= 1.11)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_min >  1.11)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  1.94)
							{
								if (feature_extraction->accel_y.acc_y_mean_square <= 3.96)
								{
									if (feature_extraction->accel_x.acc_x_median <= 0.59)
									{
										return 2;
									}
									if (feature_extraction->accel_x.acc_x_median >  0.59)
									{
										if (feature_extraction->gyro_x.gyro_x_find_kurtosis <= -0.71)
										{
											return 0;
										}
										if (feature_extraction->gyro_x.gyro_x_find_kurtosis >  -0.71)
										{
											return 2;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean_square >  3.96)
								{
									if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.12)
									{
										return 2;
									}
									if (feature_extraction->gyro_y.gyro_y_mean_square >  0.12)
									{
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 0.13)
										{
											return 1;
										}
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  0.13)
										{
											return 2;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  1.00)
						{
							if (feature_extraction->accel_x.acc_x_median <= 0.12)
							{
								return 2;
							}
							if (feature_extraction->accel_x.acc_x_median >  0.12)
							{
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 0.01)
								{
									if (feature_extraction->accel_mag.acc_magnitude_max <= 3.04)
									{
										return 3;
									}
									if (feature_extraction->accel_mag.acc_magnitude_max >  3.04)
									{
										return 2;
									}
								}
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  0.01)
								{
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.08)
									{
										if (feature_extraction->accel_x.acc_x_time_series_complexity <= 1.39)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_time_series_complexity >  1.39)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.08)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 0.47)
										{
											return 2;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  0.47)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.24)
					{
						if (feature_extraction->accel_mag.acc_magnitude_min <= 0.95)
						{
							if (feature_extraction->accel_y.acc_y_min <= -1.12)
							{
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 7.10)
								{
									return 2;
								}
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  7.10)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.17)
									{
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis <= -1.48)
										{
											return 2;
										}
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis >  -1.48)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.17)
									{
										if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.31)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.31)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_min >  -1.12)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.50)
								{
									if (feature_extraction->accel_z.acc_z_std <= 0.33)
									{
										return 3;
									}
									if (feature_extraction->accel_z.acc_z_std >  0.33)
									{
										return 4;
									}
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.50)
								{
									if (feature_extraction->gyro_y.gyro_y_std <= 0.85)
									{
										return 2;
									}
									if (feature_extraction->gyro_y.gyro_y_std >  0.85)
									{
										if (feature_extraction->gyro_z.gyro_z_std <= 1.24)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_std >  1.24)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_min >  0.95)
						{
							if (feature_extraction->accel_x.acc_x_max <= 0.70)
							{
								if (feature_extraction->accel_y.acc_y_median <= -1.86)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 3.67)
									{
										if (feature_extraction->accel_y.acc_y_mean_square <= 3.41)
										{
											return 2;
										}
										if (feature_extraction->accel_y.acc_y_mean_square >  3.41)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  3.67)
									{
										return 2;
									}
								}
								if (feature_extraction->accel_y.acc_y_median >  -1.86)
								{
									if (feature_extraction->accel_z.acc_z_min <= -0.36)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 263.31)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  263.31)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_min >  -0.36)
									{
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 6.05)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  6.05)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_max >  0.70)
							{
								if (feature_extraction->gyro_x.gyro_x_IQR <= 0.98)
								{
									if (feature_extraction->accel_z.acc_z_max <= 0.88)
									{
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 14.08)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  14.08)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_z.acc_z_max >  0.88)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 12.87)
										{
											return 3;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  12.87)
										{
											return 2;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_IQR >  0.98)
								{
									if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 80.87)
									{
										if (feature_extraction->accel_y.acc_y_mean_square <= 3.64)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_square >  3.64)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_absolut_energy >  80.87)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 311.36)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  311.36)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
			}
			if (feature_extraction->accel_x.acc_x_median >  0.61)
			{
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 5.00)
				{
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 3.79)
					{
						if (feature_extraction->gyro_x.gyro_x_mean <= 0.07)
						{
							if (feature_extraction->accel_z.acc_z_mean  <= 0.28)
							{
								if (feature_extraction->accel_x.acc_x_mean_absolute_deviation <= 0.11)
								{
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 0.45)
									{
										if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis <= 2.66)
										{
											return 1;
										}
										if (feature_extraction->accel_mag.acc_magnitude_find_kurtosis >  2.66)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  0.45)
									{
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 1.68)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  1.68)
										{
											return 4;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_mean_absolute_deviation >  0.11)
								{
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 9.63)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.44)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.44)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  9.63)
									{
										if (feature_extraction->accel_z.acc_z_time_series_complexity <= 0.67)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_time_series_complexity >  0.67)
										{
											return 0;
										}
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_mean  >  0.28)
							{
								if (feature_extraction->accel_x.acc_x_min <= 0.63)
								{
									if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 20.14)
									{
										if (feature_extraction->accel_z.acc_z_find_kurtosis <= 0.75)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_kurtosis >  0.75)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  20.14)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 12.72)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  12.72)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_min >  0.63)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_square <= 3.66)
									{
										if (feature_extraction->gyro_y.gyro_y_max <= 2.58)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_max >  2.58)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_square >  3.66)
									{
										if (feature_extraction->accel_x.acc_x_median <= 1.32)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  1.32)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_x.gyro_x_mean >  0.07)
						{
							if (feature_extraction->accel_x.acc_x_min <= 0.53)
							{
								if (feature_extraction->accel_y.acc_y_euclidian_norm <= 5.65)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error <= 33.82)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 6.05)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  6.05)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error >  33.82)
									{
										if (feature_extraction->accel_x.acc_x_euclidian_norm <= 6.07)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_euclidian_norm >  6.07)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_euclidian_norm >  5.65)
								{
									if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.39)
									{
										if (feature_extraction->accel_z.acc_z_mean  <= 0.22)
										{
											return 2;
										}
										if (feature_extraction->accel_z.acc_z_mean  >  0.22)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.39)
									{
										if (feature_extraction->gyro_x.gyro_x_std <= 0.84)
										{
											return 2;
										}
										if (feature_extraction->gyro_x.gyro_x_std >  0.84)
										{
											return 3;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_min >  0.53)
							{
								if (feature_extraction->accel_x.acc_x_median <= 2.02)
								{
									if (feature_extraction->accel_y.acc_y_median <= -0.16)
									{
										if (feature_extraction->accel_y.acc_y_find_skewness <= -3.82)
										{
											return 1;
										}
										if (feature_extraction->accel_y.acc_y_find_skewness >  -3.82)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_median >  -0.16)
									{
										if (feature_extraction->gyro_z.gyro_z_find_skewness <= 0.78)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_skewness >  0.78)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_median >  2.02)
								{
									if (feature_extraction->accel_y.acc_y_mean_square <= 0.06)
									{
										if (feature_extraction->accel_x.acc_x_time_series_complexity <= 0.42)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_time_series_complexity >  0.42)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_square >  0.06)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 0.02)
										{
											return 1;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  0.02)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  3.79)
					{
						if (feature_extraction->accel_mag.acc_magnitude_mean <= 2.26)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 1.82)
							{
								if (feature_extraction->accel_x.acc_x_find_skewness <= 0.39)
								{
									if (feature_extraction->accel_x.acc_x_euclidian_norm <= 6.78)
									{
										if (feature_extraction->accel_y.acc_y_mean_square <= 1.14)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_square >  1.14)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_x.acc_x_euclidian_norm >  6.78)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 6.70)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  6.70)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_find_skewness >  0.39)
								{
									if (feature_extraction->gyro_x.gyro_x_IQR <= 1.37)
									{
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error <= 24.13)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error >  24.13)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_IQR >  1.37)
									{
										if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.03)
										{
											return 2;
										}
										if (feature_extraction->gyro_z.gyro_z_mean_square >  0.03)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_mean >  1.82)
							{
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 27.16)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 2.24)
									{
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 9.97)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  9.97)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  2.24)
									{
										if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation <= 0.86)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation >  0.86)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  27.16)
								{
									if (feature_extraction->accel_z.acc_z_mean_square <= 1.00)
									{
										if (feature_extraction->accel_x.acc_x_mean <= 0.89)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean >  0.89)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean_square >  1.00)
									{
										if (feature_extraction->gyro_z.gyro_z_IQR <= 1.52)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_IQR >  1.52)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_mag.acc_magnitude_mean >  2.26)
						{
							if (feature_extraction->accel_mag.acc_magnitude_max <= 2.41)
							{
								if (feature_extraction->accel_y.acc_y_max <= -0.17)
								{
									return 1;
								}
								if (feature_extraction->accel_y.acc_y_max >  -0.17)
								{
									if (feature_extraction->gyro_x.gyro_x_mean_square <= 0.03)
									{
										if (feature_extraction->accel_x.acc_x_min <= 1.95)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_min >  1.95)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_mean_square >  0.03)
									{
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 6.89)
										{
											return 2;
										}
										if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  6.89)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_max >  2.41)
							{
								if (feature_extraction->accel_mag.acc_magnitude_std <= 0.15)
								{
									if (feature_extraction->accel_y.acc_y_mean_square <= 0.11)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 13.67)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  13.67)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_square >  0.11)
									{
										if (feature_extraction->accel_x.acc_x_absolut_energy <= 183.92)
										{
											return 2;
										}
										if (feature_extraction->accel_x.acc_x_absolut_energy >  183.92)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_std >  0.15)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 1.40)
									{
										return 0;
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  1.40)
									{
										if (feature_extraction->accel_x.acc_x_absolut_energy <= 182.50)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolut_energy >  182.50)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  5.00)
				{
					if (feature_extraction->accel_y.acc_y_mean <= 0.13)
					{
						if (feature_extraction->accel_z.acc_z_mean_square <= 0.95)
						{
							if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 6.19)
							{
								if (feature_extraction->accel_x.acc_x_find_skewness <= 0.45)
								{
									if (feature_extraction->accel_z.acc_z_euclidian_norm <= 3.47)
									{
										if (feature_extraction->accel_mag.acc_magnitude_min <= 0.70)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_min >  0.70)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_euclidian_norm >  3.47)
									{
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 6.47)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  6.47)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_find_skewness >  0.45)
								{
									if (feature_extraction->accel_z.acc_z_max <= 0.77)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean <= 1.48)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean >  1.48)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_z.acc_z_max >  0.77)
									{
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 8.65)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  8.65)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  6.19)
							{
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 9.20)
								{
									if (feature_extraction->accel_z.acc_z_mean  <= -0.06)
									{
										if (feature_extraction->accel_y.acc_y_absolut_energy <= 19.28)
										{
											return 1;
										}
										if (feature_extraction->accel_y.acc_y_absolut_energy >  19.28)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean  >  -0.06)
									{
										if (feature_extraction->accel_x.acc_x_min <= -0.62)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_min >  -0.62)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  9.20)
								{
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 48.82)
									{
										if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 0.84)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  0.84)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  48.82)
									{
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 11.33)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  11.33)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_z.acc_z_mean_square >  0.95)
						{
							if (feature_extraction->accel_x.acc_x_median <= 1.01)
							{
								if (feature_extraction->accel_z.acc_z_IQR <= 0.30)
								{
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 0.69)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR <= 1.34)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR >  1.34)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  0.69)
									{
										if (feature_extraction->accel_mag.acc_magnitude_median <= 1.50)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_median >  1.50)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_IQR >  0.30)
								{
									if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 1.28)
									{
										if (feature_extraction->accel_x.acc_x_mean_square <= 0.83)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean_square >  0.83)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  1.28)
									{
										if (feature_extraction->accel_z.acc_z_std <= 0.37)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_std >  0.37)
										{
											return 4;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_median >  1.01)
							{
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 33.60)
								{
									if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 8.44)
									{
										if (feature_extraction->accel_mag.acc_magnitude_max <= 2.51)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_max >  2.51)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  8.44)
									{
										if (feature_extraction->accel_x.acc_x_std  <= 0.35)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_std  >  0.35)
										{
											return 4;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  33.60)
								{
									if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 0.78)
									{
										if (feature_extraction->accel_z.acc_z_max <= 1.40)
										{
											return 3;
										}
										if (feature_extraction->accel_z.acc_z_max >  1.40)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  0.78)
									{
										if (feature_extraction->accel_x.acc_x_max <= 1.56)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_max >  1.56)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_mean >  0.13)
					{
						if (feature_extraction->accel_x.acc_x_euclidian_norm <= 6.22)
						{
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 6.79)
							{
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 9.79)
								{
									if (feature_extraction->accel_x.acc_x_find_skewness <= -0.52)
									{
										if (feature_extraction->accel_y.acc_y_time_series_complexity <= 2.23)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_time_series_complexity >  2.23)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_find_skewness >  -0.52)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.60)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.60)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  9.79)
								{
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 5.19)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 217.08)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  217.08)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  5.19)
									{
										if (feature_extraction->gyro_x.gyro_x_mean <= 0.04)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_mean >  0.04)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  6.79)
							{
								if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.88)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_std <= 0.79)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.18)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.18)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_std >  0.79)
									{
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 0.23)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  0.23)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.88)
								{
									if (feature_extraction->gyro_y.gyro_y_median <= 0.29)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 2.22)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_mean >  2.22)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_median >  0.29)
									{
										if (feature_extraction->accel_z.acc_z_mean  <= 0.99)
										{
											return 3;
										}
										if (feature_extraction->accel_z.acc_z_mean  >  0.99)
										{
											return 4;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_euclidian_norm >  6.22)
						{
							if (feature_extraction->accel_z.acc_z_find_kurtosis <= 2.15)
							{
								if (feature_extraction->accel_y.acc_y_median <= 0.64)
								{
									if (feature_extraction->accel_mag.acc_magnitude_max <= 2.44)
									{
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 4.50)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  4.50)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_max >  2.44)
									{
										if (feature_extraction->gyro_x.gyro_x_find_kurtosis <= 1.53)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_find_kurtosis >  1.53)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_median >  0.64)
								{
									if (feature_extraction->accel_x.acc_x_absolut_energy <= 73.81)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 15.57)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  15.57)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolut_energy >  73.81)
									{
										if (feature_extraction->accel_z.acc_z_std <= 0.27)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_std >  0.27)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_find_kurtosis >  2.15)
							{
								if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 1.75)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 29.34)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 3.33)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_square >  3.33)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  29.34)
									{
										if (feature_extraction->accel_x.acc_x_find_skewness <= 0.22)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_find_skewness >  0.22)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_mag.gyro_magnitude_mean >  1.75)
								{
									if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation <= 1.04)
									{
										if (feature_extraction->accel_mag.acc_magnitude_max <= 2.40)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_max >  2.40)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_mean_absolute_deviation >  1.04)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.42)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.42)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.21)
	{
		if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 12.36)
		{
			if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 7.81)
			{
				if (feature_extraction->accel_z.acc_z_median <= 0.27)
				{
					if (feature_extraction->accel_mag.acc_magnitude_median <= 2.21)
					{
						if (feature_extraction->gyro_y.gyro_y_min <= -2.70)
						{
							if (feature_extraction->accel_x.acc_x_mean <= 0.04)
							{
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 8.02)
								{
									if (feature_extraction->accel_mag.acc_magnitude_mean <= 1.87)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 4.01)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  4.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_mean >  1.87)
									{
										if (feature_extraction->accel_x.acc_x_median <= -1.89)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  -1.89)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  8.02)
								{
									if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation <= 0.79)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 17.10)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  17.10)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_mean_absolute_deviation >  0.79)
									{
										if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.15)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_mean_square >  0.15)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean >  0.04)
							{
								if (feature_extraction->accel_y.acc_y_absolut_energy <= 45.31)
								{
									if (feature_extraction->accel_z.acc_z_min <= -0.24)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_max <= 3.96)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_max >  3.96)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_min >  -0.24)
									{
										return 2;
									}
								}
								if (feature_extraction->accel_y.acc_y_absolut_energy >  45.31)
								{
									if (feature_extraction->gyro_x.gyro_x_std <= 0.61)
									{
										return 4;
									}
									if (feature_extraction->gyro_x.gyro_x_std >  0.61)
									{
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 10.18)
										{
											return 2;
										}
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  10.18)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_y.gyro_y_min >  -2.70)
						{
							if (feature_extraction->accel_x.acc_x_min <= -1.17)
							{
								if (feature_extraction->accel_x.acc_x_absolut_energy <= 111.01)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 2.24)
									{
										if (feature_extraction->accel_y.acc_y_mean <= -0.07)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  -0.07)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  2.24)
									{
										if (feature_extraction->gyro_z.gyro_z_find_skewness <= -0.69)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_skewness >  -0.69)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_absolut_energy >  111.01)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 3.04)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 9.84)
										{
											return 3;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  9.84)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  3.04)
									{
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 10.54)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  10.54)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_min >  -1.17)
							{
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 9.48)
								{
									if (feature_extraction->accel_x.acc_x_absolut_energy <= 98.67)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 12.50)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  12.50)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_x.acc_x_absolut_energy >  98.67)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean <= 2.13)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean >  2.13)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  9.48)
								{
									if (feature_extraction->accel_y.acc_y_time_series_complexity <= 3.39)
									{
										if (feature_extraction->accel_x.acc_x_max <= 1.58)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_max >  1.58)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_time_series_complexity >  3.39)
									{
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 14.69)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  14.69)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_mag.acc_magnitude_median >  2.21)
					{
						if (feature_extraction->accel_y.acc_y_mean_square <= 0.09)
						{
							if (feature_extraction->accel_x.acc_x_time_series_complexity <= 1.60)
							{
								return 0;
							}
							if (feature_extraction->accel_x.acc_x_time_series_complexity >  1.60)
							{
								return 1;
							}
						}
						if (feature_extraction->accel_y.acc_y_mean_square >  0.09)
						{
							if (feature_extraction->accel_mag.acc_magnitude_median <= 2.40)
							{
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 4.36)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 2.94)
									{
										if (feature_extraction->accel_mag.acc_magnitude_std <= 0.28)
										{
											return 1;
										}
										if (feature_extraction->accel_mag.acc_magnitude_std >  0.28)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  2.94)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_square <= 0.01)
										{
											return 4;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_square >  0.01)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  4.36)
								{
									if (feature_extraction->gyro_y.gyro_y_std <= 0.91)
									{
										return 3;
									}
									if (feature_extraction->gyro_y.gyro_y_std >  0.91)
									{
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate <= 3.60)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_zero_crossing_rate >  3.60)
										{
											return 0;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_median >  2.40)
							{
								if (feature_extraction->gyro_x.gyro_x_IQR <= 1.68)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 1.72)
									{
										if (feature_extraction->accel_y.acc_y_max <= -0.12)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_max >  -0.12)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  1.72)
									{
										if (feature_extraction->accel_x.acc_x_euclidian_norm <= 10.92)
										{
											return 4;
										}
										if (feature_extraction->accel_x.acc_x_euclidian_norm >  10.92)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_IQR >  1.68)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_square <= 4.48)
									{
										return 0;
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_square >  4.48)
									{
										if (feature_extraction->accel_z.acc_z_time_series_complexity <= 1.17)
										{
											return 4;
										}
										if (feature_extraction->accel_z.acc_z_time_series_complexity >  1.17)
										{
											return 2;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_z.acc_z_median >  0.27)
				{
					if (feature_extraction->accel_x.acc_x_find_skewness <= -0.05)
					{
						if (feature_extraction->accel_y.acc_y_mean <= -0.15)
						{
							if (feature_extraction->accel_x.acc_x_mean <= 0.46)
							{
								if (feature_extraction->accel_z.acc_z_IQR <= 0.25)
								{
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 17.24)
									{
										return 2;
									}
									if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  17.24)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_z.acc_z_IQR >  0.25)
								{
									if (feature_extraction->accel_x.acc_x_min <= -1.90)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 8.35)
										{
											return 4;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  8.35)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_min >  -1.90)
									{
										if (feature_extraction->accel_y.acc_y_std <= 0.49)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_std >  0.49)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean >  0.46)
							{
								if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 5.05)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 15.01)
									{
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 6.25)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  6.25)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  15.01)
									{
										if (feature_extraction->gyro_y.gyro_y_std <= 0.79)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_std >  0.79)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  5.05)
								{
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.13)
									{
										return 3;
									}
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.13)
									{
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 9.36)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  9.36)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_mean >  -0.15)
						{
							if (feature_extraction->accel_mag.acc_magnitude_std <= 0.33)
							{
								if (feature_extraction->accel_x.acc_x_median <= 0.96)
								{
									if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 5.76)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 9.91)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  9.91)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  5.76)
									{
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 0.66)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  0.66)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_median >  0.96)
								{
									if (feature_extraction->accel_z.acc_z_std <= 0.45)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.45)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.45)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_z.acc_z_std >  0.45)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.30)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.30)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_std >  0.33)
							{
								if (feature_extraction->accel_z.acc_z_time_series_complexity <= 2.17)
								{
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 2.95)
									{
										return 2;
									}
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  2.95)
									{
										if (feature_extraction->gyro_y.gyro_y_find_skewness <= 0.15)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_find_skewness >  0.15)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_time_series_complexity >  2.17)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis <= -0.01)
									{
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 6.30)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  6.30)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis >  -0.01)
									{
										if (feature_extraction->accel_z.acc_z_find_skewness <= -0.47)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_skewness >  -0.47)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_x.acc_x_find_skewness >  -0.05)
					{
						if (feature_extraction->accel_x.acc_x_std  <= 0.41)
						{
							if (feature_extraction->accel_x.acc_x_mean <= 0.17)
							{
								if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 2.95)
								{
									if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 46.47)
									{
										if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 4.71)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  4.71)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_absolut_energy >  46.47)
									{
										if (feature_extraction->accel_y.acc_y_std <= 0.28)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_std >  0.28)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_mean_square >  2.95)
								{
									if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 67.96)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.42)
										{
											return 4;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.42)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_absolut_energy >  67.96)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 125.45)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  125.45)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean >  0.17)
							{
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 5.01)
								{
									if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error <= 59.12)
									{
										if (feature_extraction->accel_y.acc_y_median <= 0.59)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_median >  0.59)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error >  59.12)
									{
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 0.98)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  0.98)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  5.01)
								{
									if (feature_extraction->accel_mag.acc_magnitude_min <= 1.16)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 3.41)
										{
											return 3;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  3.41)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_min >  1.16)
									{
										if (feature_extraction->accel_x.acc_x_min <= 0.75)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_min >  0.75)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_std  >  0.41)
						{
							if (feature_extraction->accel_x.acc_x_mean <= 0.38)
							{
								if (feature_extraction->accel_x.acc_x_median <= -0.54)
								{
									if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 3.96)
									{
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 15.61)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  15.61)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  3.96)
									{
										if (feature_extraction->accel_y.acc_y_mean <= -0.02)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  -0.02)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_median >  -0.54)
								{
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 6.52)
									{
										if (feature_extraction->accel_z.acc_z_IQR <= 0.36)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_IQR >  0.36)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  6.52)
									{
										if (feature_extraction->accel_y.acc_y_mean <= 0.20)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  0.20)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_mean >  0.38)
							{
								if (feature_extraction->accel_x.acc_x_time_series_complexity <= 2.93)
								{
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 6.79)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.63)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.63)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  6.79)
									{
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 5.73)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  5.73)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_time_series_complexity >  2.93)
								{
									if (feature_extraction->accel_z.acc_z_mean_square <= 0.56)
									{
										if (feature_extraction->accel_z.acc_z_find_kurtosis <= 4.82)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_kurtosis >  4.82)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean_square >  0.56)
									{
										if (feature_extraction->accel_y.acc_y_euclidian_norm <= 3.34)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_euclidian_norm >  3.34)
										{
											return 4;
										}
									}
								}
							}
						}
					}
				}
			}
			if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  7.81)
			{
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 13.42)
				{
					if (feature_extraction->accel_y.acc_y_IQR <= 0.28)
					{
						if (feature_extraction->accel_y.acc_y_absolut_energy <= 38.07)
						{
							if (feature_extraction->accel_z.acc_z_absolut_energy <= 40.54)
							{
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes <= 14.24)
								{
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 5.88)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.15)
										{
											return 1;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.15)
										{
											return 2;
										}
									}
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  5.88)
									{
										if (feature_extraction->gyro_z.gyro_z_median <= -0.73)
										{
											return 4;
										}
										if (feature_extraction->gyro_z.gyro_z_median >  -0.73)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_absolute_sum_of_changes >  14.24)
								{
									if (feature_extraction->gyro_x.gyro_x_mean_square <= 0.21)
									{
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error <= 43.75)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error >  43.75)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_mean_square >  0.21)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.64)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.64)
										{
											return 4;
										}
									}
								}
							}
							if (feature_extraction->accel_z.acc_z_absolut_energy >  40.54)
							{
								if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 10.82)
								{
									if (feature_extraction->accel_y.acc_y_absolut_energy <= 4.37)
									{
										return 1;
									}
									if (feature_extraction->accel_y.acc_y_absolut_energy >  4.37)
									{
										return 4;
									}
								}
								if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  10.82)
								{
									return 0;
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_absolut_energy >  38.07)
						{
							if (feature_extraction->accel_y.acc_y_max <= 1.61)
							{
								if (feature_extraction->accel_x.acc_x_IQR <= 0.49)
								{
									return 2;
								}
								if (feature_extraction->accel_x.acc_x_IQR >  0.49)
								{
									return 1;
								}
							}
							if (feature_extraction->accel_y.acc_y_max >  1.61)
							{
								if (feature_extraction->accel_x.acc_x_euclidian_norm <= 3.27)
								{
									return 0;
								}
								if (feature_extraction->accel_x.acc_x_euclidian_norm >  3.27)
								{
									return 4;
								}
							}
						}
					}
					if (feature_extraction->accel_y.acc_y_IQR >  0.28)
					{
						if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 10.04)
						{
							if (feature_extraction->gyro_z.gyro_z_mean <= 0.17)
							{
								if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 6.00)
								{
									if (feature_extraction->accel_z.acc_z_time_series_complexity <= 3.08)
									{
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 36.34)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  36.34)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_time_series_complexity >  3.08)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 1.52)
										{
											return 0;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  1.52)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  6.00)
								{
									if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= -0.25)
									{
										if (feature_extraction->gyro_z.gyro_z_mean <= -0.08)
										{
											return 2;
										}
										if (feature_extraction->gyro_z.gyro_z_mean >  -0.08)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  -0.25)
									{
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 4.63)
										{
											return 2;
										}
										if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  4.63)
										{
											return 3;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_mean >  0.17)
							{
								if (feature_extraction->accel_z.acc_z_min <= -0.26)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 39.79)
									{
										return 3;
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  39.79)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 103.48)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  103.48)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_min >  -0.26)
								{
									if (feature_extraction->accel_z.acc_z_time_series_complexity <= 1.76)
									{
										if (feature_extraction->gyro_x.gyro_x_median <= -0.09)
										{
											return 2;
										}
										if (feature_extraction->gyro_x.gyro_x_median >  -0.09)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_time_series_complexity >  1.76)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 21.48)
										{
											return 3;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  21.48)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  10.04)
						{
							if (feature_extraction->accel_x.acc_x_euclidian_norm <= 3.66)
							{
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 14.90)
								{
									if (feature_extraction->accel_y.acc_y_std <= 0.32)
									{
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 3.37)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  3.37)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_std >  0.32)
									{
										if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.26)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean_square >  0.26)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  14.90)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.25)
									{
										return 3;
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.25)
									{
										if (feature_extraction->accel_x.acc_x_median <= -0.31)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  -0.31)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_euclidian_norm >  3.66)
							{
								if (feature_extraction->accel_y.acc_y_max <= 0.57)
								{
									if (feature_extraction->gyro_x.gyro_x_median <= -0.30)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 16.49)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  16.49)
										{
											return 1;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_median >  -0.30)
									{
										if (feature_extraction->gyro_x.gyro_x_absolut_energy <= 50.58)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_absolut_energy >  50.58)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_max >  0.57)
								{
									if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.37)
									{
										if (feature_extraction->gyro_y.gyro_y_IQR <= 1.67)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_IQR >  1.67)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.37)
									{
										if (feature_extraction->gyro_x.gyro_x_IQR <= 2.93)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_IQR >  2.93)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  13.42)
				{
					if (feature_extraction->accel_y.acc_y_find_skewness <= -1.59)
					{
						if (feature_extraction->accel_x.acc_x_mean <= -0.03)
						{
							if (feature_extraction->accel_y.acc_y_time_series_complexity <= 2.96)
							{
								if (feature_extraction->gyro_y.gyro_y_median <= -0.06)
								{
									return 1;
								}
								if (feature_extraction->gyro_y.gyro_y_median >  -0.06)
								{
									return 3;
								}
							}
							if (feature_extraction->accel_y.acc_y_time_series_complexity >  2.96)
							{
								return 4;
							}
						}
						if (feature_extraction->accel_x.acc_x_mean >  -0.03)
						{
							return 3;
						}
					}
					if (feature_extraction->accel_y.acc_y_find_skewness >  -1.59)
					{
						if (feature_extraction->accel_x.acc_x_max <= 1.78)
						{
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 4.91)
							{
								if (feature_extraction->accel_y.acc_y_mean_square <= 0.49)
								{
									if (feature_extraction->gyro_z.gyro_z_median <= 1.97)
									{
										if (feature_extraction->accel_y.acc_y_find_skewness <= 1.84)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_find_skewness >  1.84)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_median >  1.97)
									{
										if (feature_extraction->accel_x.acc_x_time_series_complexity <= 4.80)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_time_series_complexity >  4.80)
										{
											return 4;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean_square >  0.49)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.06)
									{
										return 2;
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.06)
									{
										if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error <= 36.00)
										{
											return 1;
										}
										if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error >  36.00)
										{
											return 4;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  4.91)
							{
								if (feature_extraction->accel_mag.acc_magnitude_min <= 0.73)
								{
									if (feature_extraction->accel_x.acc_x_mean <= -0.22)
									{
										if (feature_extraction->accel_x.acc_x_time_series_complexity <= 4.02)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_time_series_complexity >  4.02)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean >  -0.22)
									{
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 13.84)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  13.84)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_min >  0.73)
								{
									return 0;
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_max >  1.78)
						{
							if (feature_extraction->gyro_z.gyro_z_absolut_energy <= 51.83)
							{
								if (feature_extraction->accel_y.acc_y_median <= -0.23)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 1.55)
									{
										return 4;
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean >  1.55)
									{
										return 3;
									}
								}
								if (feature_extraction->accel_y.acc_y_median >  -0.23)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 13.92)
									{
										return 0;
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  13.92)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 15.28)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  15.28)
										{
											return 3;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_absolut_energy >  51.83)
							{
								if (feature_extraction->gyro_y.gyro_y_mean <= -0.11)
								{
									if (feature_extraction->accel_y.acc_y_time_series_complexity <= 3.80)
									{
										return 4;
									}
									if (feature_extraction->accel_y.acc_y_time_series_complexity >  3.80)
									{
										return 3;
									}
								}
								if (feature_extraction->gyro_y.gyro_y_mean >  -0.11)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 12.18)
									{
										return 1;
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  12.18)
									{
										if (feature_extraction->accel_y.acc_y_find_kurtosis <= 0.46)
										{
											return 1;
										}
										if (feature_extraction->accel_y.acc_y_find_kurtosis >  0.46)
										{
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  12.36)
		{
			if (feature_extraction->accel_mag.acc_magnitude_min <= 0.58)
			{
				if (feature_extraction->accel_x.acc_x_mean <= 0.39)
				{
					if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 15.64)
					{
						if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 10.57)
						{
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 7.15)
							{
								if (feature_extraction->accel_x.acc_x_find_skewness <= 0.56)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 11.12)
									{
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 55.75)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  55.75)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  11.12)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.72)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.72)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_find_skewness >  0.56)
								{
									if (feature_extraction->accel_y.acc_y_mean_square <= 0.15)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 10.12)
										{
											return 1;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  10.12)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_square >  0.15)
									{
										if (feature_extraction->gyro_z.gyro_z_mean_square <= 2.27)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_mean_square >  2.27)
										{
											return 4;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  7.15)
							{
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 5.86)
								{
									if (feature_extraction->accel_x.acc_x_std  <= 0.68)
									{
										if (feature_extraction->accel_x.acc_x_median <= -1.04)
										{
											return 1;
										}
										if (feature_extraction->accel_x.acc_x_median >  -1.04)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_std  >  0.68)
									{
										if (feature_extraction->gyro_x.gyro_x_std <= 1.17)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_std >  1.17)
										{
											return 2;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  5.86)
								{
									if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 2.81)
									{
										if (feature_extraction->accel_z.acc_z_min <= -0.84)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_min >  -0.84)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  2.81)
									{
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate <= 5.91)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_zero_crossing_rate >  5.91)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  10.57)
						{
							if (feature_extraction->gyro_x.gyro_x_time_series_complexity <= 6.14)
							{
								if (feature_extraction->accel_z.acc_z_IQR <= 0.37)
								{
									if (feature_extraction->accel_x.acc_x_sum_of_squares_error <= 31.04)
									{
										if (feature_extraction->accel_y.acc_y_IQR <= 0.28)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_IQR >  0.28)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_sum_of_squares_error >  31.04)
									{
										if (feature_extraction->accel_y.acc_y_mean <= -0.03)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean >  -0.03)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_IQR >  0.37)
								{
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 12.92)
									{
										if (feature_extraction->accel_x.acc_x_mean_square <= 0.07)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_mean_square >  0.07)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  12.92)
									{
										if (feature_extraction->accel_x.acc_x_absolut_energy <= 24.80)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolut_energy >  24.80)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_x.gyro_x_time_series_complexity >  6.14)
							{
								if (feature_extraction->gyro_z.gyro_z_IQR <= 0.48)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation <= 0.57)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 0.98)
										{
											return 3;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  0.98)
										{
											return 4;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation >  0.57)
									{
										if (feature_extraction->accel_x.acc_x_median <= 0.12)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_median >  0.12)
										{
											return 0;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_IQR >  0.48)
								{
									if (feature_extraction->gyro_x.gyro_x_find_kurtosis <= 0.57)
									{
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 1.26)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  1.26)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_find_kurtosis >  0.57)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 12.14)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  12.14)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  15.64)
					{
						if (feature_extraction->accel_x.acc_x_mean_square <= 0.48)
						{
							if (feature_extraction->accel_x.acc_x_zero_crossing_rate <= 8.40)
							{
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes <= 20.16)
								{
									if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.01)
									{
										if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error <= 57.45)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_sum_of_squares_error >  57.45)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_mean_square >  0.01)
									{
										if (feature_extraction->accel_x.acc_x_std  <= 0.82)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_std  >  0.82)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes >  20.16)
								{
									if (feature_extraction->accel_mag.acc_magnitude_max <= 2.47)
									{
										if (feature_extraction->accel_y.acc_y_mean_square <= 0.06)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_square >  0.06)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_max >  2.47)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 18.23)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  18.23)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_x.acc_x_zero_crossing_rate >  8.40)
							{
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 6.17)
								{
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 7.16)
									{
										if (feature_extraction->accel_x.acc_x_min <= -2.02)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_min >  -2.02)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  7.16)
									{
										if (feature_extraction->accel_y.acc_y_time_series_complexity <= 2.56)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_time_series_complexity >  2.56)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  6.17)
								{
									if (feature_extraction->gyro_x.gyro_x_mean_square <= 1.15)
									{
										if (feature_extraction->accel_z.acc_z_median <= 0.47)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_median >  0.47)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_mean_square >  1.15)
									{
										if (feature_extraction->gyro_x.gyro_x_find_skewness <= 1.86)
										{
											return 4;
										}
										if (feature_extraction->gyro_x.gyro_x_find_skewness >  1.86)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_mean_square >  0.48)
						{
							if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 8.59)
							{
								if (feature_extraction->accel_y.acc_y_sum_of_squares_error <= 4.78)
								{
									if (feature_extraction->accel_x.acc_x_find_kurtosis <= 1.28)
									{
										if (feature_extraction->accel_z.acc_z_std <= 0.45)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_std >  0.45)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_find_kurtosis >  1.28)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR <= 0.50)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR >  0.50)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_sum_of_squares_error >  4.78)
								{
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 6.83)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 9.45)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  9.45)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  6.83)
									{
										if (feature_extraction->accel_mag.acc_magnitude_find_skewness <= -0.46)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_find_skewness >  -0.46)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  8.59)
							{
								if (feature_extraction->gyro_y.gyro_y_mean_square <= 0.01)
								{
									if (feature_extraction->accel_x.acc_x_IQR <= 1.50)
									{
										if (feature_extraction->gyro_x.gyro_x_find_skewness <= -1.12)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_find_skewness >  -1.12)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_IQR >  1.50)
									{
										return 4;
									}
								}
								if (feature_extraction->gyro_y.gyro_y_mean_square >  0.01)
								{
									if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.26)
									{
										if (feature_extraction->gyro_z.gyro_z_find_skewness <= 0.71)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_skewness >  0.71)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.26)
									{
										if (feature_extraction->accel_x.acc_x_absolut_energy <= 94.80)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolut_energy >  94.80)
										{
											return 5;
										}
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_x.acc_x_mean >  0.39)
				{
					if (feature_extraction->accel_x.acc_x_median <= 0.85)
					{
						if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 2.10)
						{
							if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes <= 13.59)
							{
								if (feature_extraction->accel_z.acc_z_median <= 0.88)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 15.12)
									{
										if (feature_extraction->accel_z.acc_z_euclidian_norm <= 4.01)
										{
											return 3;
										}
										if (feature_extraction->accel_z.acc_z_euclidian_norm >  4.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  15.12)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_median <= 2.35)
										{
											return 4;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_median >  2.35)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_median >  0.88)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 14.61)
									{
										if (feature_extraction->gyro_x.gyro_x_median <= 0.49)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_median >  0.49)
										{
											return 4;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  14.61)
									{
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation <= 1.10)
										{
											return 4;
										}
										if (feature_extraction->gyro_x.gyro_x_mean_absolute_deviation >  1.10)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes >  13.59)
							{
								if (feature_extraction->accel_y.acc_y_mean <= -0.21)
								{
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 4.32)
									{
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.37)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.37)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  4.32)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.28)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.28)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean >  -0.21)
								{
									if (feature_extraction->accel_x.acc_x_time_series_complexity <= 7.24)
									{
										if (feature_extraction->accel_z.acc_z_time_series_complexity <= 4.01)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_time_series_complexity >  4.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_time_series_complexity >  7.24)
									{
										if (feature_extraction->accel_z.acc_z_max <= 2.48)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_max >  2.48)
										{
											return 3;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  2.10)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation <= 0.58)
							{
								if (feature_extraction->accel_y.acc_y_median <= -0.17)
								{
									if (feature_extraction->accel_x.acc_x_IQR <= 1.45)
									{
										if (feature_extraction->gyro_x.gyro_x_mean <= -0.30)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_mean >  -0.30)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_IQR >  1.45)
									{
										return 4;
									}
								}
								if (feature_extraction->accel_y.acc_y_median >  -0.17)
								{
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 15.27)
									{
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.22)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.22)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  15.27)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity <= 1.29)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity >  1.29)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation >  0.58)
							{
								if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation <= 0.31)
								{
									if (feature_extraction->gyro_z.gyro_z_std <= 0.77)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 11.79)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  11.79)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_std >  0.77)
									{
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis <= -0.91)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_find_kurtosis >  -0.91)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation >  0.31)
								{
									if (feature_extraction->accel_y.acc_y_time_series_complexity <= 4.22)
									{
										if (feature_extraction->gyro_y.gyro_y_median <= -0.01)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_median >  -0.01)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_time_series_complexity >  4.22)
									{
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 18.53)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  18.53)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_x.acc_x_median >  0.85)
					{
						if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes <= 10.35)
						{
							if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 13.67)
							{
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error <= 23.32)
								{
									if (feature_extraction->accel_y.acc_y_find_skewness <= 1.26)
									{
										if (feature_extraction->gyro_y.gyro_y_mean <= 1.11)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_mean >  1.11)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_y.acc_y_find_skewness >  1.26)
									{
										if (feature_extraction->gyro_y.gyro_y_IQR <= 1.18)
										{
											return 4;
										}
										if (feature_extraction->gyro_y.gyro_y_IQR >  1.18)
										{
											return 3;
										}
									}
								}
								if (feature_extraction->accel_z.acc_z_sum_of_squares_error >  23.32)
								{
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 16.50)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_min <= 0.77)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_min >  0.77)
										{
											return 3;
										}
									}
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  16.50)
									{
										return 4;
									}
								}
							}
							if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  13.67)
							{
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 20.08)
								{
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 11.90)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR <= 0.75)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_IQR >  0.75)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  11.90)
									{
										if (feature_extraction->gyro_y.gyro_y_min <= -2.64)
										{
											return 0;
										}
										if (feature_extraction->gyro_y.gyro_y_min >  -2.64)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  20.08)
								{
									if (feature_extraction->gyro_y.gyro_y_mean <= 0.66)
									{
										if (feature_extraction->accel_z.acc_z_find_kurtosis <= -0.37)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_kurtosis >  -0.37)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_mean >  0.66)
									{
										if (feature_extraction->accel_z.acc_z_mean  <= 0.82)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean  >  0.82)
										{
											return 3;
										}
									}
								}
							}
						}
						if (feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes >  10.35)
						{
							if (feature_extraction->accel_y.acc_y_median <= 0.27)
							{
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.35)
								{
									if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= -1.16)
									{
										if (feature_extraction->gyro_x.gyro_x_IQR <= 1.16)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_IQR >  1.16)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  -1.16)
									{
										if (feature_extraction->accel_z.acc_z_mean_square <= 0.70)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_mean_square >  0.70)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.35)
								{
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation <= 0.33)
									{
										if (feature_extraction->accel_y.acc_y_median <= -0.52)
										{
											return 2;
										}
										if (feature_extraction->accel_y.acc_y_median >  -0.52)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_mean_absolute_deviation >  0.33)
									{
										if (feature_extraction->gyro_z.gyro_z_mean <= 0.41)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_mean >  0.41)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_median >  0.27)
							{
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 6.11)
								{
									if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 8.68)
									{
										if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= -0.91)
										{
											return 4;
										}
										if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  -0.91)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  8.68)
									{
										return 4;
									}
								}
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  6.11)
								{
									if (feature_extraction->accel_y.acc_y_find_skewness <= -1.36)
									{
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 7.08)
										{
											return 0;
										}
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  7.08)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_y.acc_y_find_skewness >  -1.36)
									{
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 75.61)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  75.61)
										{
											return 3;
										}
									}
								}
							}
						}
					}
				}
			}
			if (feature_extraction->accel_mag.acc_magnitude_min >  0.58)
			{
				if (feature_extraction->accel_z.acc_z_IQR <= 0.42)
				{
					if (feature_extraction->accel_x.acc_x_mean <= 0.71)
					{
						if (feature_extraction->accel_x.acc_x_median <= 0.83)
						{
							if (feature_extraction->gyro_y.gyro_y_find_skewness <= -0.27)
							{
								if (feature_extraction->gyro_z.gyro_z_IQR <= 1.37)
								{
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 13.17)
									{
										if (feature_extraction->accel_z.acc_z_min <= -0.11)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_min >  -0.11)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  13.17)
									{
										if (feature_extraction->gyro_z.gyro_z_absolut_energy <= 39.30)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolut_energy >  39.30)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_IQR >  1.37)
								{
									if (feature_extraction->accel_z.acc_z_find_kurtosis <= 0.64)
									{
										if (feature_extraction->accel_x.acc_x_find_skewness <= 0.55)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_find_skewness >  0.55)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_z.acc_z_find_kurtosis >  0.64)
									{
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 5.98)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  5.98)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->gyro_y.gyro_y_find_skewness >  -0.27)
							{
								if (feature_extraction->accel_x.acc_x_median <= -0.88)
								{
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm <= 10.89)
									{
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes <= 14.21)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes >  14.21)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm >  10.89)
									{
										if (feature_extraction->accel_y.acc_y_find_kurtosis <= 4.16)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_find_kurtosis >  4.16)
										{
											return 1;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_median >  -0.88)
								{
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 10.95)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 16.36)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  16.36)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  10.95)
									{
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 9.97)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  9.97)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_x.acc_x_median >  0.83)
						{
							if (feature_extraction->accel_y.acc_y_time_series_complexity <= 3.92)
							{
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm <= 9.21)
								{
									if (feature_extraction->gyro_x.gyro_x_IQR <= 0.55)
									{
										return 4;
									}
									if (feature_extraction->gyro_x.gyro_x_IQR >  0.55)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_mean <= 2.63)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_mean >  2.63)
										{
											return 4;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_euclidian_norm >  9.21)
								{
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm <= 7.16)
									{
										return 0;
									}
									if (feature_extraction->gyro_y.gyro_y_euclidian_norm >  7.16)
									{
										if (feature_extraction->gyro_z.gyro_z_min <= -1.05)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_min >  -1.05)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_time_series_complexity >  3.92)
							{
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error <= 3.38)
								{
									return 1;
								}
								if (feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error >  3.38)
								{
									if (feature_extraction->accel_x.acc_x_min <= -1.30)
									{
										if (feature_extraction->gyro_z.gyro_z_std <= 0.45)
										{
											return 0;
										}
										if (feature_extraction->gyro_z.gyro_z_std >  0.45)
										{
											return 4;
										}
									}
									if (feature_extraction->accel_x.acc_x_min >  -1.30)
									{
										return 3;
									}
								}
							}
						}
					}
					if (feature_extraction->accel_x.acc_x_mean >  0.71)
					{
						if (feature_extraction->accel_z.acc_z_std <= 0.43)
						{
							if (feature_extraction->gyro_z.gyro_z_mean <= -0.31)
							{
								if (feature_extraction->accel_mag.acc_magnitude_absolut_energy <= 95.48)
								{
									if (feature_extraction->gyro_x.gyro_x_mean <= -0.98)
									{
										if (feature_extraction->gyro_y.gyro_y_IQR <= 1.39)
										{
											return 4;
										}
										if (feature_extraction->gyro_y.gyro_y_IQR >  1.39)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_mean >  -0.98)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 10.71)
										{
											return 0;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  10.71)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_absolut_energy >  95.48)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation <= 0.52)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation <= 0.42)
										{
											return 1;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation >  0.42)
										{
											return 4;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation >  0.52)
									{
										if (feature_extraction->accel_x.acc_x_absolut_energy <= 81.29)
										{
											return 5;
										}
										if (feature_extraction->accel_x.acc_x_absolut_energy >  81.29)
										{
											return 1;
										}
									}
								}
							}
							if (feature_extraction->gyro_z.gyro_z_mean >  -0.31)
							{
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes <= 5.32)
								{
									if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 40.79)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness <= 0.54)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_find_skewness >  0.54)
										{
											return 0;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  40.79)
									{
										if (feature_extraction->gyro_x.gyro_x_mean <= -0.27)
										{
											return 0;
										}
										if (feature_extraction->gyro_x.gyro_x_mean >  -0.27)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes >  5.32)
								{
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm <= 11.69)
									{
										if (feature_extraction->accel_y.acc_y_find_skewness <= -0.62)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_find_skewness >  -0.62)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_euclidian_norm >  11.69)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 11.99)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  11.99)
										{
											return 0;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_z.acc_z_std >  0.43)
						{
							if (feature_extraction->accel_y.acc_y_max <= 1.35)
							{
								if (feature_extraction->gyro_z.gyro_z_median <= -0.38)
								{
									if (feature_extraction->accel_x.acc_x_min <= -1.70)
									{
										return 3;
									}
									if (feature_extraction->accel_x.acc_x_min >  -1.70)
									{
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy <= 217.15)
										{
											return 5;
										}
										if (feature_extraction->gyro_mag.gyro_magnitude_absolut_energy >  217.15)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_median >  -0.38)
								{
									if (feature_extraction->gyro_z.gyro_z_find_kurtosis <= 2.61)
									{
										if (feature_extraction->accel_z.acc_z_find_kurtosis <= 4.48)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_find_kurtosis >  4.48)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_find_kurtosis >  2.61)
									{
										return 4;
									}
								}
							}
							if (feature_extraction->accel_y.acc_y_max >  1.35)
							{
								if (feature_extraction->accel_x.acc_x_mean_square <= 0.74)
								{
									if (feature_extraction->gyro_z.gyro_z_mean_square <= 0.77)
									{
										if (feature_extraction->gyro_z.gyro_z_absolut_energy <= 23.92)
										{
											return 4;
										}
										if (feature_extraction->gyro_z.gyro_z_absolut_energy >  23.92)
										{
											return 3;
										}
									}
									if (feature_extraction->gyro_z.gyro_z_mean_square >  0.77)
									{
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 3.73)
										{
											return 4;
										}
										if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  3.73)
										{
											return 2;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_mean_square >  0.74)
								{
									if (feature_extraction->accel_y.acc_y_mean <= 1.18)
									{
										if (feature_extraction->accel_mag.acc_magnitude_IQR <= 0.40)
										{
											return 5;
										}
										if (feature_extraction->accel_mag.acc_magnitude_IQR >  0.40)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean >  1.18)
									{
										return 2;
									}
								}
							}
						}
					}
				}
				if (feature_extraction->accel_z.acc_z_IQR >  0.42)
				{
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes <= 20.39)
					{
						if (feature_extraction->accel_y.acc_y_max <= 0.55)
						{
							if (feature_extraction->accel_mag.acc_magnitude_mean_square <= 1.68)
							{
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.30)
								{
									if (feature_extraction->accel_x.acc_x_mean_square <= 0.32)
									{
										if (feature_extraction->accel_y.acc_y_min <= -1.71)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_min >  -1.71)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_mean_square >  0.32)
									{
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm <= 6.61)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_euclidian_norm >  6.61)
										{
											return 3;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.30)
								{
									return 2;
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_mean_square >  1.68)
							{
								if (feature_extraction->accel_x.acc_x_find_skewness <= 0.05)
								{
									if (feature_extraction->accel_mag.acc_magnitude_max <= 2.86)
									{
										if (feature_extraction->accel_y.acc_y_euclidian_norm <= 6.45)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_euclidian_norm >  6.45)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_max >  2.86)
									{
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate <= 2.83)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_zero_crossing_rate >  2.83)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_find_skewness >  0.05)
								{
									if (feature_extraction->accel_z.acc_z_median <= -0.85)
									{
										return 2;
									}
									if (feature_extraction->accel_z.acc_z_median >  -0.85)
									{
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error <= 29.26)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_sum_of_squares_error >  29.26)
										{
											return 5;
										}
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_max >  0.55)
						{
							if (feature_extraction->accel_mag.acc_magnitude_min <= 0.84)
							{
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 10.72)
								{
									if (feature_extraction->gyro_x.gyro_x_IQR <= 2.44)
									{
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate <= 10.87)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_zero_crossing_rate >  10.87)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_x.gyro_x_IQR >  2.44)
									{
										if (feature_extraction->gyro_z.gyro_z_std <= 1.26)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_std >  1.26)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  10.72)
								{
									if (feature_extraction->accel_y.acc_y_mean <= -0.08)
									{
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate <= 1.31)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_zero_crossing_rate >  1.31)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_mean >  -0.08)
									{
										if (feature_extraction->accel_z.acc_z_absolut_energy <= 23.20)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_absolut_energy >  23.20)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_min >  0.84)
							{
								if (feature_extraction->accel_mag.acc_magnitude_median <= 2.09)
								{
									if (feature_extraction->accel_x.acc_x_median <= 0.95)
									{
										if (feature_extraction->accel_z.acc_z_max <= 2.17)
										{
											return 5;
										}
										if (feature_extraction->accel_z.acc_z_max >  2.17)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_x.acc_x_median >  0.95)
									{
										if (feature_extraction->gyro_x.gyro_x_max <= 0.69)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_max >  0.69)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_median >  2.09)
								{
									if (feature_extraction->accel_y.acc_y_find_skewness <= -0.43)
									{
										if (feature_extraction->gyro_z.gyro_z_median <= 0.82)
										{
											return 2;
										}
										if (feature_extraction->gyro_z.gyro_z_median >  0.82)
										{
											return 1;
										}
									}
									if (feature_extraction->accel_y.acc_y_find_skewness >  -0.43)
									{
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity <= 2.73)
										{
											return 5;
										}
										if (feature_extraction->gyro_z.gyro_z_time_series_complexity >  2.73)
										{
											return 5;
										}
									}
								}
							}
						}
					}
					if (feature_extraction->accel_z.acc_z_absolute_sum_of_changes >  20.39)
					{
						if (feature_extraction->accel_y.acc_y_mean_absolute_deviation <= 0.25)
						{
							if (feature_extraction->accel_x.acc_x_median <= 0.77)
							{
								if (feature_extraction->gyro_z.gyro_z_std <= 1.11)
								{
									if (feature_extraction->accel_x.acc_x_mean <= -1.39)
									{
										return 1;
									}
									if (feature_extraction->accel_x.acc_x_mean >  -1.39)
									{
										if (feature_extraction->gyro_y.gyro_y_find_kurtosis <= -1.19)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_find_kurtosis >  -1.19)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->gyro_z.gyro_z_std >  1.11)
								{
									return 1;
								}
							}
							if (feature_extraction->accel_x.acc_x_median >  0.77)
							{
								if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error <= 11.77)
								{
									return 1;
								}
								if (feature_extraction->gyro_z.gyro_z_sum_of_squares_error >  11.77)
								{
									if (feature_extraction->accel_y.acc_y_max <= 1.09)
									{
										return 0;
									}
									if (feature_extraction->accel_y.acc_y_max >  1.09)
									{
										return 4;
									}
								}
							}
						}
						if (feature_extraction->accel_y.acc_y_mean_absolute_deviation >  0.25)
						{
							if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity <= 3.38)
							{
								if (feature_extraction->accel_x.acc_x_median <= -1.43)
								{
									if (feature_extraction->accel_mag.acc_magnitude_std <= 0.46)
									{
										if (feature_extraction->accel_y.acc_y_euclidian_norm <= 4.09)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_euclidian_norm >  4.09)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_mag.acc_magnitude_std >  0.46)
									{
										if (feature_extraction->gyro_y.gyro_y_absolut_energy <= 55.68)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_absolut_energy >  55.68)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_x.acc_x_median >  -1.43)
								{
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm <= 13.12)
									{
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity <= 1.77)
										{
											return 5;
										}
										if (feature_extraction->gyro_y.gyro_y_time_series_complexity >  1.77)
										{
											return 5;
										}
									}
									if (feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm >  13.12)
									{
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes <= 15.16)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_absolute_sum_of_changes >  15.16)
										{
											return 5;
										}
									}
								}
							}
							if (feature_extraction->accel_mag.acc_magnitude_time_series_complexity >  3.38)
							{
								if (feature_extraction->accel_mag.acc_magnitude_min <= 0.95)
								{
									if (feature_extraction->accel_y.acc_y_max <= 1.13)
									{
										if (feature_extraction->accel_y.acc_y_time_series_complexity <= 2.62)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_time_series_complexity >  2.62)
										{
											return 5;
										}
									}
									if (feature_extraction->accel_y.acc_y_max >  1.13)
									{
										if (feature_extraction->gyro_x.gyro_x_min <= -0.68)
										{
											return 5;
										}
										if (feature_extraction->gyro_x.gyro_x_min >  -0.68)
										{
											return 5;
										}
									}
								}
								if (feature_extraction->accel_mag.acc_magnitude_min >  0.95)
								{
									if (feature_extraction->accel_y.acc_y_euclidian_norm <= 3.72)
									{
										if (feature_extraction->gyro_z.gyro_z_median <= -0.55)
										{
											return 3;
										}
										if (feature_extraction->gyro_z.gyro_z_median >  -0.55)
										{
											return 0;
										}
									}
									if (feature_extraction->accel_y.acc_y_euclidian_norm >  3.72)
									{
										if (feature_extraction->accel_y.acc_y_find_kurtosis <= 0.36)
										{
											return 5;
										}
										if (feature_extraction->accel_y.acc_y_find_kurtosis >  0.36)
										{
											return 2;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
return 5;
}
