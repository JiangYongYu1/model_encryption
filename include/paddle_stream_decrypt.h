//   Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <stdio.h>
#include <string>

#include "deploy_declare.h"

#ifndef PADDLE_MODEL_PROTECT_API_PADDLE_STREAM_DECRYPT_H
#define PADDLE_MODEL_PROTECT_API_PADDLE_STREAM_DECRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * check file (un)encrypted?
 * @param file_path
 * @return
 */

PD_INFER_DECL int paddle_check_stream_encrypted(std::istream& cipher_stream);

PD_INFER_DECL int decrypt_stream(std::istream& cipher_stream,
                                 std::ostream& plain_stream,
                                 const std::string& key_base64);

#ifdef __cplusplus
}
#endif

#endif  // PADDLE_MODEL_PROTECT_API_PADDLE_MODEL_DECRYPT_H
