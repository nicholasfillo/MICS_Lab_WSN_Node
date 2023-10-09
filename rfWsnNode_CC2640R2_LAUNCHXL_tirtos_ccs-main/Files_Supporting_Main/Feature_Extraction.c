#include <stdio.h>
#include <math.h>
#include "Feature_Extraction.h"

float find_mean(Feature_Extraction* feature_extraction) {
    float sum = 0.0;
    float mean = 0.0;
    int i;
    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        sum += feature_extraction->input_arr[i];
    }

    if (sum == 0.0) {
        return 0.0;
    }

    mean = sum / feature_extraction->input_arr_size;
    return mean;
}

float find_median(Feature_Extraction* feature_extraction) {
    sort_arr(feature_extraction);

    return ((feature_extraction->input_arr[1] + feature_extraction->input_arr[2]) / 2);
}

float find_max(Feature_Extraction* feature_extraction) {
    int i;
    float max = feature_extraction->input_arr[0];
    for (i = 1; i < feature_extraction->input_arr_size; i ++) {
        if (feature_extraction->input_arr[i] > max) {
            max = feature_extraction->input_arr[i];
        }
    }
    return max;
}

float find_min(Feature_Extraction* feature_extraction) {
    int i;
    float min = feature_extraction->input_arr[0];
    for (i = 1; i < feature_extraction->input_arr_size; i ++) {
        if (feature_extraction->input_arr[i] < min) {
            min = feature_extraction->input_arr[i];
        }
    }
    return min;
}

float find_std(Feature_Extraction* feature_extraction) {
    float variance = 0.0;
    float std;
    int i; 

    float mean = find_mean(feature_extraction);

    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        float deviation = feature_extraction->input_arr[i] - mean;        
        variance += deviation * deviation;
    }
    variance /= feature_extraction->input_arr_size;

    std = sqrtf(variance);
    return std;
}

float euclidian_norm(Feature_Extraction* feature_extraction) {
    int i;
    float euclidian_norm_sum = 0;
    float euclidian_norm_arr[feature_extraction->input_arr_size];
    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        euclidian_norm_arr[i] = fabs(feature_extraction->input_arr[i]) * fabs(feature_extraction->input_arr[i]);
        euclidian_norm_sum += euclidian_norm_arr[i];
    }
    return sqrtf(euclidian_norm_sum);
}

float mean_absolute_deviation(Feature_Extraction* feature_extraction) {
    float MAD;
    int i;

    float mean = find_mean(feature_extraction);

    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        MAD += fabs(feature_extraction->input_arr[i] - mean);
    }
    MAD /= feature_extraction->input_arr_size; 

    return MAD;
}

float mean_square(Feature_Extraction* feature_extraction) {
    float mean_squared;

    float mean = find_mean(feature_extraction);
    mean_squared = mean * mean;

    return mean_squared;
}

float sum_of_squares_error(Feature_Extraction* feature_extraction) {
    int i;
    float sum_of_squares_error = 0.0;

    float mean = find_mean(feature_extraction);

    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        sum_of_squares_error += (feature_extraction->input_arr[i] - mean) * (feature_extraction->input_arr[i] - mean); 
    }

    return sum_of_squares_error;
}

int zero_crossing_rate(Feature_Extraction* feature_extraction) {
    int count = 0;
    int i;
    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        if ((feature_extraction->input_arr[i-1] > 0 && feature_extraction->input_arr[i]) || (feature_extraction->input_arr[i-1] < 0 && feature_extraction->input_arr[i] >= 0)) {
            count += 1;
        }
    }
    return count;
}

float find_kurtosis(Feature_Extraction* feature_extraction) {
    float mean = find_mean(feature_extraction);
    float std = find_std(feature_extraction);

    if (std == 0.0) {
        printf("Warning Division By Zero\n");
        return 0.0;
    }

    int i;
    float kurtosis = 0.0;
    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        kurtosis += (((pow((feature_extraction->input_arr[i] - mean), 4))/feature_extraction->input_arr_size) / (pow(std, 4))) - 3;
    }
    return kurtosis;
}

float find_skewness(Feature_Extraction* feature_extraction) {
    float mean = find_mean(feature_extraction);
    float std = find_std(feature_extraction);

    if (std == 0.0) {
        printf("Warning Division By Zero\n");
        return 0.0;
    }

    int i;
    float skewness = 0.0;
    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        skewness += (((pow((feature_extraction->input_arr[i] - mean), 3))/feature_extraction->input_arr_size) / (pow(std, 3)));
    }
    return skewness;
}

float absolut_energy(Feature_Extraction* feature_extraction) {
    float absolut_energy = 0.0;
    int i;

    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        absolut_energy += (feature_extraction->input_arr[i] * feature_extraction->input_arr[i]);
    }
    return absolut_energy;
}

float absolute_sum_of_changes(Feature_Extraction* feature_extraction) {
    float absolute_sum_of_changes = 0.0;
    int i;
    for (i = 1; i < feature_extraction->input_arr_size; i ++) {
        absolute_sum_of_changes += fabs(feature_extraction->input_arr[i] - feature_extraction->input_arr[i - 1]);
    }
    return absolute_sum_of_changes;
}

float time_series_complexity(Feature_Extraction* feature_extraction) {
    float diff[feature_extraction->input_arr_size - 1];
    float complexity;
    int i;
    for (i = 0; i < feature_extraction->input_arr_size - 1; i ++) {
        diff[i] = feature_extraction->input_arr[i + 1] - feature_extraction->input_arr[i];
    }

    for (i = 0; i < feature_extraction->input_arr_size; i ++) {
        complexity += (diff[i] * diff[i]);
    }
    complexity = sqrtf(complexity);

    return complexity;
}

float find_Q1(Feature_Extraction* feature_extraction, int percentile) {
    sort_arr(feature_extraction);

}

float find_Q3(Feature_Extraction* feature_extraction, int percentile) {
    sort_arr(feature_extraction);

}

void swap(float *x, float *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_arr(Feature_Extraction* feature_extraction) {
    int i, j, min;

    for (i = 0; i < feature_extraction->input_arr_size - 1; i ++) {
        min = i;
        for (j = i + 1; j < feature_extraction->input_arr_size; j ++) {
            if (feature_extraction->input_arr[j] < feature_extraction->input_arr[min]) {
                min = j;
            }
            swap(&feature_extraction->input_arr[min], &feature_extraction->input_arr[j]);
        }
    }
}

void extract_time_domain_features(Feature_Extraction* feature_extraction, int specification) {
    float mean = find_mean(feature_extraction);
    float max = find_max(feature_extraction);
    float min = find_min(feature_extraction);
    float std = find_std(feature_extraction);
    float median = find_median(feature_extraction);

    //Q1 = 
    //Q3 =
    //IQR = Q1 - Q3

    float euclidian_norm_td = euclidian_norm(feature_extraction);
    float mean_absolute_deviation_td = mean_absolute_deviation(feature_extraction);
    float mean_square_td = mean_square(feature_extraction);
    float sum_of_squares_error_td = sum_of_squares_error(feature_extraction);
    int zero_crossing_rate_td = zero_crossing_rate(feature_extraction);
    float find_kurtosis_td = find_kurtosis(feature_extraction);
    float find_skewness_td = find_skewness(feature_extraction);
    float absolut_energy_td  = absolut_energy(feature_extraction);
    float absolute_sum_of_changes_td = absolute_sum_of_changes(feature_extraction);
    float time_series_complexity_td = time_series_complexity(feature_extraction);

    switch (specification) {
        case ACC_X:
            feature_extraction->accel_x.acc_x_mean = mean;       
            feature_extraction->accel_x.acc_x_std = std;
            feature_extraction->accel_x.acc_x_max = max;
            feature_extraction->accel_x.acc_x_min = min;
            feature_extraction->accel_x.acc_x_median = median;

            feature_extraction->accel_x.acc_x_euclidian_norm = euclidian_norm_td;
            feature_extraction->accel_x.acc_x_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->accel_x.acc_x_mean_square = mean_square_td;
            feature_extraction->accel_x.acc_x_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->accel_x.acc_x_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->accel_x.acc_x_find_kurtosis = find_kurtosis_td;
            feature_extraction->accel_x.acc_x_find_skewness = find_skewness_td;
            feature_extraction->accel_x.acc_x_absolut_energy = absolut_energy_td;
            feature_extraction->accel_x.acc_x_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->accel_x.acc_x_time_series_complexity = time_series_complexity_td;
        break;

        case ACC_Y:
            feature_extraction->accel_y.acc_y_mean = mean;       
            feature_extraction->accel_y.acc_y_std = std;
            feature_extraction->accel_y.acc_y_max = max;
            feature_extraction->accel_y.acc_y_min = min;
            feature_extraction->accel_y.acc_y_median = median;

            feature_extraction->accel_y.acc_y_euclidian_norm = euclidian_norm_td;
            feature_extraction->accel_y.acc_y_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->accel_y.acc_y_mean_square = mean_square_td;
            feature_extraction->accel_y.acc_y_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->accel_y.acc_y_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->accel_y.acc_y_find_kurtosis = find_kurtosis_td;
            feature_extraction->accel_y.acc_y_find_skewness = find_skewness_td;
            feature_extraction->accel_y.acc_y_absolut_energy = absolut_energy_td;
            feature_extraction->accel_y.acc_y_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->accel_y.acc_y_time_series_complexity = time_series_complexity_td;
        break;

        case ACC_Z:
            feature_extraction->accel_z.acc_z_mean = mean;       
            feature_extraction->accel_z.acc_z_std = std;
            feature_extraction->accel_z.acc_z_max = max;
            feature_extraction->accel_z.acc_z_min = min;
            feature_extraction->accel_z.acc_z_median = median;

            feature_extraction->accel_z.acc_z_euclidian_norm = euclidian_norm_td;
            feature_extraction->accel_z.acc_z_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->accel_z.acc_z_mean_square = mean_square_td;
            feature_extraction->accel_z.acc_z_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->accel_z.acc_z_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->accel_z.acc_z_find_kurtosis = find_kurtosis_td;
            feature_extraction->accel_z.acc_z_find_skewness = find_skewness_td;
            feature_extraction->accel_z.acc_z_absolut_energy = absolut_energy_td;
            feature_extraction->accel_z.acc_z_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->accel_z.acc_z_time_series_complexity = time_series_complexity_td;
        break;

        case ACC_MAG:
            feature_extraction->accel_mag.acc_magnitude_mean = mean;       
            feature_extraction->accel_mag.acc_magnitude_std = std;
            feature_extraction->accel_mag.acc_magnitude_max = max;
            feature_extraction->accel_mag.acc_magnitude_min = min;
            feature_extraction->accel_mag.acc_magnitude_median = median;

            feature_extraction->accel_mag.acc_magnitude_euclidian_norm = euclidian_norm_td;
            feature_extraction->accel_mag.acc_magnitude_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->accel_mag.acc_magnitude_mean_square = mean_square_td;
            feature_extraction->accel_mag.acc_magnitude_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->accel_mag.acc_magnitude_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->accel_mag.acc_magnitude_find_kurtosis = find_kurtosis_td;
            feature_extraction->accel_mag.acc_magnitude_find_skewness = find_skewness_td;
            feature_extraction->accel_mag.acc_magnitude_absolut_energy = absolut_energy_td;
            feature_extraction->accel_mag.acc_magnitude_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->accel_mag.acc_magnitude_time_series_complexity = time_series_complexity_td;
        break;

        case GYRO_X:
            feature_extraction->gyro_x.gyro_x_mean = mean;       
            feature_extraction->gyro_x.gyro_x_std = std;
            feature_extraction->gyro_x.gyro_x_max = max;
            feature_extraction->gyro_x.gyro_x_min = min;
            feature_extraction->gyro_x.gyro_x_median = median;

            feature_extraction->gyro_x.gyro_x_euclidian_norm = euclidian_norm_td;
            feature_extraction->gyro_x.gyro_x_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->gyro_x.gyro_x_mean_square = mean_square_td;
            feature_extraction->gyro_x.gyro_x_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->gyro_x.gyro_x_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->gyro_x.gyro_x_find_kurtosis = find_kurtosis_td;
            feature_extraction->gyro_x.gyro_x_find_skewness = find_skewness_td;
            feature_extraction->gyro_x.gyro_x_absolut_energy = absolut_energy_td;
            feature_extraction->gyro_x.gyro_x_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->gyro_x.gyro_x_time_series_complexity = time_series_complexity_td;
        break;

        case GYRO_Y:
            feature_extraction->gyro_y.gyro_y_mean = mean;       
            feature_extraction->gyro_y.gyro_y_std = std;
            feature_extraction->gyro_y.gyro_y_max = max;
            feature_extraction->gyro_y.gyro_y_min = min;
            feature_extraction->gyro_y.gyro_y_median = median;

            feature_extraction->gyro_y.gyro_y_euclidian_norm = euclidian_norm_td;
            feature_extraction->gyro_y.gyro_y_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->gyro_y.gyro_y_mean_square = mean_square_td;
            feature_extraction->gyro_y.gyro_y_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->gyro_y.gyro_y_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->gyro_y.gyro_y_find_kurtosis = find_kurtosis_td;
            feature_extraction->gyro_y.gyro_y_find_skewness = find_skewness_td;
            feature_extraction->gyro_y.gyro_y_absolut_energy = absolut_energy_td;
            feature_extraction->gyro_y.gyro_y_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->gyro_y.gyro_y_time_series_complexity = time_series_complexity_td;
        break;
        
        case GYRO_Z:
            feature_extraction->gyro_z.gyro_z_mean = mean;       
            feature_extraction->gyro_z.gyro_z_std = std;
            feature_extraction->gyro_z.gyro_z_max = max;
            feature_extraction->gyro_z.gyro_z_min = min;
            feature_extraction->gyro_z.gyro_z_median = median;

            feature_extraction->gyro_z.gyro_z_euclidian_norm = euclidian_norm_td;
            feature_extraction->gyro_z.gyro_z_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->gyro_z.gyro_z_mean_square = mean_square_td;
            feature_extraction->gyro_z.gyro_z_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->gyro_z.gyro_z_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->gyro_z.gyro_z_find_kurtosis = find_kurtosis_td;
            feature_extraction->gyro_z.gyro_z_find_skewness = find_skewness_td;
            feature_extraction->gyro_z.gyro_z_absolut_energy = absolut_energy_td;
            feature_extraction->gyro_z.gyro_z_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->gyro_z.gyro_z_time_series_complexity = time_series_complexity_td;
        break;
    
        case GYRO_MAG:
            feature_extraction->gyro_mag.gyro_magnitude_mean = mean;       
            feature_extraction->gyro_mag.gyro_magnitude_std = std;
            feature_extraction->gyro_mag.gyro_magnitude_max = max;
            feature_extraction->gyro_mag.gyro_magnitude_min = min;
            feature_extraction->gyro_mag.gyro_magnitude_median = median;

            feature_extraction->gyro_mag.gyro_magnitude_euclidian_norm = euclidian_norm_td;
            feature_extraction->gyro_mag.gyro_magnitude_mean_absolute_deviation = mean_absolute_deviation_td;
            feature_extraction->gyro_mag.gyro_magnitude_mean_square = mean_square_td;
            feature_extraction->gyro_mag.gyro_magnitude_sum_of_squares_error = sum_of_squares_error_td;
            feature_extraction->gyro_mag.gyro_magnitude_zero_crossing_rate = zero_crossing_rate_td;
            feature_extraction->gyro_mag.gyro_magnitude_find_kurtosis = find_kurtosis_td;
            feature_extraction->gyro_mag.gyro_magnitude_find_skewness = find_skewness_td;
            feature_extraction->gyro_mag.gyro_magnitude_absolut_energy = absolut_energy_td;
            feature_extraction->gyro_mag.gyro_magnitude_absolute_sum_of_changes = absolute_sum_of_changes_td;
            feature_extraction->gyro_mag.gyro_magnitude_time_series_complexity = time_series_complexity_td;
        break;

        default:
            break;
    }
}

//Feature Extraction Struct Initialization
/*
Feature_Extraction Feature_Extraction_Construct() {
    Feature_Extraction feature_extraction;
    feature_extraction.input_arr_size = 4;
    
    int i;
    for (i = 0; i < 4; i ++) {
        feature_extraction.input_arr[i] = 0.0;
    }
    return feature_extraction;
}*/