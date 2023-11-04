#ifndef FEATURE_EXTRACTION_H
#define FEATURE_EXTRACTION_H

#define ACC_X       101
#define ACC_Y       102
#define ACC_Z       103
#define ACC_MAG     104
#define GYRO_X      105
#define GYRO_Y      106
#define GYRO_Z      107
#define GYRO_MAG    108

//Struct containing all acceleration x values that need to be extracted
struct acceleration_x {
    float acc_x, acc_x_mean, acc_x_std, acc_x_max, acc_x_min, acc_x_median, acc_x_Q1, acc_x_Q3, acc_x_IQR, acc_x_euclidian_norm, acc_x_mean_absolute_deviation, acc_x_mean_square, acc_x_sum_of_squares_error, 
          acc_x_zero_crossing_rate, acc_x_find_kurtosis, acc_x_find_skewness, acc_x_absolut_energy, acc_x_absolute_sum_of_changes, acc_x_time_series_complexity;
};

//Struct containing all acceleration y values that need to be extracted
struct acceleration_y  {
    float acc_y, acc_y_mean, acc_y_std, acc_y_max, acc_y_min, acc_y_median, acc_y_Q1, acc_y_Q3, acc_y_IQR, acc_y_euclidian_norm, acc_y_mean_absolute_deviation, acc_y_mean_square, acc_y_sum_of_squares_error, 
          acc_y_zero_crossing_rate, acc_y_find_kurtosis, acc_y_find_skewness, acc_y_absolut_energy, acc_y_absolute_sum_of_changes, acc_y_time_series_complexity;
};

//Struct containing all acceleration z values that need to be extracted
struct acceleration_z  {
    float acc_z, acc_z_mean, acc_z_std, acc_z_max, acc_z_min, acc_z_median, acc_z_Q1, acc_z_Q3, acc_z_IQR, acc_z_euclidian_norm, acc_z_mean_absolute_deviation, acc_z_mean_square, acc_z_sum_of_squares_error, 
          acc_z_zero_crossing_rate, acc_z_find_kurtosis, acc_z_find_skewness, acc_z_absolut_energy, acc_z_absolute_sum_of_changes, acc_z_time_series_complexity;
};

//Struct containing all acceleration magnitude values that need to be extracted
struct acceleration_magnitude  {
    float acc_magnitude, acc_magnitude_mean, acc_magnitude_std, acc_magnitude_max, acc_magnitude_min, acc_magnitude_median, acc_magnitude_Q1, acc_magnitude_Q3, acc_magnitude_IQR, acc_magnitude_euclidian_norm, 
          acc_magnitude_mean_absolute_deviation, acc_magnitude_mean_square, acc_magnitude_sum_of_squares_error, acc_magnitude_zero_crossing_rate, acc_magnitude_find_kurtosis, 
          acc_magnitude_find_skewness, acc_magnitude_absolut_energy, acc_magnitude_absolute_sum_of_changes, acc_magnitude_time_series_complexity;
};

//Struct containing all gyroscope x values that need to be extracted
struct gyroscope_x {
    float gyro_x, gyro_x_mean, gyro_x_std, gyro_x_max, gyro_x_min, gyro_x_median, gyro_x_Q1, gyro_x_Q3, gyro_x_IQR, gyro_x_euclidian_norm, gyro_x_mean_absolute_deviation, gyro_x_mean_square, gyro_x_sum_of_squares_error, 
          gyro_x_zero_crossing_rate, gyro_x_find_kurtosis, gyro_x_find_skewness, gyro_x_absolut_energy, gyro_x_absolute_sum_of_changes, gyro_x_time_series_complexity;
};

//Struct containing all gyroscope y values that need to be extracted
struct gyroscope_y {
    float gyro_y, gyro_y_mean, gyro_y_std, gyro_y_max, gyro_y_min, gyro_y_median, gyro_y_Q1, gyro_y_Q3, gyro_y_IQR, gyro_y_euclidian_norm, gyro_y_mean_absolute_deviation, gyro_y_mean_square, gyro_y_sum_of_squares_error, 
          gyro_y_zero_crossing_rate, gyro_y_find_kurtosis, gyro_y_find_skewness, gyro_y_absolut_energy, gyro_y_absolute_sum_of_changes, gyro_y_time_series_complexity;
};

//Struct containing all gyroscope z values that need to be extracted
struct gyroscope_z {
    float gyro_z, gyro_z_mean, gyro_z_std, gyro_z_max, gyro_z_min, gyro_z_median, gyro_z_Q1, gyro_z_Q3, gyro_z_IQR, gyro_z_euclidian_norm, gyro_z_mean_absolute_deviation, gyro_z_mean_square, gyro_z_sum_of_squares_error, 
          gyro_z_zero_crossing_rate, gyro_z_find_kurtosis, gyro_z_find_skewness, gyro_z_absolut_energy, gyro_z_absolute_sum_of_changes, gyro_z_time_series_complexity;
};

//Struct containing all gyroscope z values that need to be extracted
struct gyroscope_magnitude {
    float gyro_magnitude, gyro_magnitude_mean, gyro_magnitude_std, gyro_magnitude_max, gyro_magnitude_min, gyro_magnitude_median, gyro_magnitude_Q1, gyro_magnitude_Q3, gyro_magnitude_IQR, gyro_magnitude_euclidian_norm, 
          gyro_magnitude_mean_absolute_deviation, gyro_magnitude_mean_square, gyro_magnitude_sum_of_squares_error, gyro_magnitude_zero_crossing_rate, gyro_magnitude_find_kurtosis, 
          gyro_magnitude_find_skewness, gyro_magnitude_absolut_energy, gyro_magnitude_absolute_sum_of_changes, gyro_magnitude_time_series_complexity;
};

//Struct containing all features
struct _Feature_Extraction
{
    struct acceleration_x accel_x;
    struct acceleration_y accel_y;
    struct acceleration_z accel_z;
    struct acceleration_magnitude accel_mag;
    struct gyroscope_x gyro_x;
    struct gyroscope_y gyro_y;
    struct gyroscope_z gyro_z;
    struct gyroscope_magnitude gyro_mag;

    int input_arr_size;
    float input_arr[4];

};
typedef struct _Feature_Extraction Feature_Extraction;


//Function to Extract Features
float find_mean(Feature_Extraction* feature_extraction);
float find_median(Feature_Extraction* feature_extraction);
float find_max(Feature_Extraction* feature_extraction);
float find_min(Feature_Extraction* feature_extraction);
float find_std(Feature_Extraction* feature_extraction);
float euclidian_norm(Feature_Extraction* feature_extraction);
float mean_absolute_deviation(Feature_Extraction* feature_extraction);
float mean_square(Feature_Extraction* feature_extraction);
float sum_of_squares_error(Feature_Extraction* feature_extraction);
int zero_crossing_rate(Feature_Extraction* feature_extraction);
float find_kurtosis(Feature_Extraction* feature_extraction);
float find_skewness(Feature_Extraction* feature_extraction);
float absolut_energy(Feature_Extraction* feature_extraction);
float absolute_sum_of_changes(Feature_Extraction* feature_extraction);
float time_series_complexity(Feature_Extraction* feature_extraction);
float percentile(Feature_Extraction* feature_extraction, int percentile);

void extract_time_domain_features(Feature_Extraction* feature_extraction, int specification);

//Sort array Functions
void swap(float *x, float *y);
void sort_arr(Feature_Extraction* feature_extraction);

#endif /*FEATURE_EXTRACTION_H*/
