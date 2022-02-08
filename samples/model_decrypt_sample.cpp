#include "iostream"

#include "paddle_model_decrypt.h"
#include "model_code.h"
#include "gflags/gflags.h"

DEFINE_string(model_filename, "G:/download/baidu_20220127/model/ls_first.pdmodel", "Path of model");
DEFINE_string(params_filename, "G:/download/baidu_20220127/model/ls_first.pdiparams", "Path of params");

int main(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    const std::string g_model_key = "X8w4zBmM62KmmjneEVZG+5us9TzS7UGgnLt93epEGg4=";
    std::string model_data = decrypt_file(FLAGS_model_filename.c_str(), g_model_key.c_str());
    std::string params_data = decrypt_file(FLAGS_params_filename.c_str(), g_model_key.c_str());
    std::cout << model_data.size() << std::endl;
    std::cout << params_data.size() << std::endl;
}