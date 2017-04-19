/*******************************************************************************
* Copyright 2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <vector>

struct conv_problem {
    int groups;
    int minibatch;
    int w;
    int h;
    int ic;
    int oc;
    int fw;
    int fh;
    int stride;
    int padd;
    int iters;
    const char *name;
};

static const std::vector<conv_problem> conv_problems = {
    // Topology: overfeat
    {1, 256, 231, 231, 3, 96, 11, 11, 4, 0, 1000, "overfeat:conv1"},
    {1, 256, 28, 28, 96, 256, 5, 5, 1, 0, 1000, "overfeat:conv2"},
    {1, 256, 12, 12, 256, 512, 3, 3, 1, 1, 1000, "overfeat:conv3"},
    {1, 256, 12, 12, 512, 1024, 3, 3, 1, 1, 1000, "overfeat:conv4"},
    {1, 256, 12, 12, 1024, 1024, 3, 3, 1, 1, 1000, "overfeat:conv5"},
    // Topology: alexnet
    {1, 256, 227, 227, 3, 96, 11, 11, 4, 0, 1000, "alexnet:conv1"},
    {2, 256, 27, 27, 96, 256, 5, 5, 1, 2, 1000, "alexnet:conv2"},
    {1, 256, 13, 13, 256, 384, 3, 3, 1, 1, 1000, "alexnet:conv3"},
    {2, 256, 13, 13, 384, 384, 3, 3, 1, 1, 1000, "alexnet:conv4"},
    {2, 256, 13, 13, 384, 256, 3, 3, 1, 1, 1000, "alexnet:conv5"},
    // Topology: vgg_19
    {1, 64, 224, 224, 3, 64, 3, 3, 1, 1, 1000, "vgg_19:conv1_1"},
    {1, 64, 224, 224, 64, 64, 3, 3, 1, 1, 1000, "vgg_19:conv1_2"},
    {1, 64, 112, 112, 64, 128, 3, 3, 1, 1, 1000, "vgg_19:conv2_1"},
    {1, 64, 112, 112, 128, 128, 3, 3, 1, 1, 1000, "vgg_19:conv2_2"},
    {1, 64, 56, 56, 128, 256, 3, 3, 1, 1, 1000, "vgg_19:conv3_1"},
    {1, 64, 56, 56, 256, 256, 3, 3, 1, 1, 1000, "vgg_19:conv3_2"},
    {1, 64, 56, 56, 256, 256, 3, 3, 1, 1, 1000, "vgg_19:conv3_3"},
    {1, 64, 56, 56, 256, 256, 3, 3, 1, 1, 1000, "vgg_19:conv3_4"},
    {1, 64, 28, 28, 256, 512, 3, 3, 1, 1, 1000, "vgg_19:conv4_1"},
    {1, 64, 28, 28, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv4_2"},
    {1, 64, 28, 28, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv4_3"},
    {1, 64, 28, 28, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv4_4"},
    {1, 64, 14, 14, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv5_1"},
    {1, 64, 14, 14, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv5_2"},
    {1, 64, 14, 14, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv5_3"},
    {1, 64, 14, 14, 512, 512, 3, 3, 1, 1, 1000, "vgg_19:conv5_4"},
    // Topology: resnet_50
    {1, 50, 224, 224, 3, 64, 7, 7, 2, 3, 1000, "resnet_50:conv1"},
    {1, 50, 56, 56, 64, 256, 1, 1, 1, 0, 1000, "resnet_50:res2a_branch1"},
    {1, 50, 56, 56, 64, 64, 1, 1, 1, 0, 1000, "resnet_50:res2a_branch2a"},
    {1, 50, 56, 56, 64, 64, 3, 3, 1, 1, 1000, "resnet_50:res2a_branch2b"},
    {1, 50, 56, 56, 64, 256, 1, 1, 1, 0, 1000, "resnet_50:res2a_branch2c"},
    {1, 50, 56, 56, 256, 64, 1, 1, 1, 0, 1000, "resnet_50:res2b_branch2a"},
    {1, 50, 56, 56, 64, 64, 3, 3, 1, 1, 1000, "resnet_50:res2b_branch2b"},
    {1, 50, 56, 56, 64, 256, 1, 1, 1, 0, 1000, "resnet_50:res2b_branch2c"},
    {1, 50, 56, 56, 256, 64, 1, 1, 1, 0, 1000, "resnet_50:res2c_branch2a"},
    {1, 50, 56, 56, 64, 64, 3, 3, 1, 1, 1000, "resnet_50:res2c_branch2b"},
    {1, 50, 56, 56, 64, 256, 1, 1, 1, 0, 1000, "resnet_50:res2c_branch2c"},
    {1, 50, 56, 56, 256, 512, 1, 1, 2, 0, 1000, "resnet_50:res3a_branch1"},
    {1, 50, 56, 56, 256, 128, 1, 1, 2, 0, 1000, "resnet_50:res3a_branch2a"},
    {1, 50, 28, 28, 128, 128, 3, 3, 1, 1, 1000, "resnet_50:res3a_branch2b"},
    {1, 50, 28, 28, 128, 512, 1, 1, 1, 0, 1000, "resnet_50:res3a_branch2c"},
    {1, 50, 28, 28, 512, 128, 1, 1, 1, 0, 1000, "resnet_50:res3b_branch2a"},
    {1, 50, 28, 28, 128, 128, 3, 3, 1, 1, 1000, "resnet_50:res3b_branch2b"},
    {1, 50, 28, 28, 128, 512, 1, 1, 1, 0, 1000, "resnet_50:res3b_branch2c"},
    {1, 50, 28, 28, 512, 128, 1, 1, 1, 0, 1000, "resnet_50:res3c_branch2a"},
    {1, 50, 28, 28, 128, 128, 3, 3, 1, 1, 1000, "resnet_50:res3c_branch2b"},
    {1, 50, 28, 28, 128, 512, 1, 1, 1, 0, 1000, "resnet_50:res3c_branch2c"},
    {1, 50, 28, 28, 512, 128, 1, 1, 1, 0, 1000, "resnet_50:res3d_branch2a"},
    {1, 50, 28, 28, 128, 128, 3, 3, 1, 1, 1000, "resnet_50:res3d_branch2b"},
    {1, 50, 28, 28, 128, 512, 1, 1, 1, 0, 1000, "resnet_50:res3d_branch2c"},
    {1, 50, 28, 28, 512, 1024, 1, 1, 2, 0, 1000, "resnet_50:res4a_branch1"},
    {1, 50, 28, 28, 512, 256, 1, 1, 2, 0, 1000, "resnet_50:res4a_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4a_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4a_branch2c"},
    {1, 50, 14, 14, 1024, 256, 1, 1, 1, 0, 1000, "resnet_50:res4b_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4b_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4b_branch2c"},
    {1, 50, 14, 14, 1024, 256, 1, 1, 1, 0, 1000, "resnet_50:res4c_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4c_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4c_branch2c"},
    {1, 50, 14, 14, 1024, 256, 1, 1, 1, 0, 1000, "resnet_50:res4d_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4d_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4d_branch2c"},
    {1, 50, 14, 14, 1024, 256, 1, 1, 1, 0, 1000, "resnet_50:res4e_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4e_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4e_branch2c"},
    {1, 50, 14, 14, 1024, 256, 1, 1, 1, 0, 1000, "resnet_50:res4f_branch2a"},
    {1, 50, 14, 14, 256, 256, 3, 3, 1, 1, 1000, "resnet_50:res4f_branch2b"},
    {1, 50, 14, 14, 256, 1024, 1, 1, 1, 0, 1000, "resnet_50:res4f_branch2c"},
    {1, 50, 14, 14, 1024, 2048, 1, 1, 2, 0, 1000, "resnet_50:res5a_branch1"},
    {1, 50, 14, 14, 1024, 512, 1, 1, 2, 0, 1000, "resnet_50:res5a_branch2a"},
    {1, 50, 7, 7, 512, 512, 3, 3, 1, 1, 1000, "resnet_50:res5a_branch2b"},
    {1, 50, 7, 7, 512, 2048, 1, 1, 1, 0, 1000, "resnet_50:res5a_branch2c"},
    {1, 50, 7, 7, 2048, 512, 1, 1, 1, 0, 1000, "resnet_50:res5b_branch2a"},
    {1, 50, 7, 7, 512, 512, 3, 3, 1, 1, 1000, "resnet_50:res5b_branch2b"},
    {1, 50, 7, 7, 512, 2048, 1, 1, 1, 0, 1000, "resnet_50:res5b_branch2c"},
    {1, 50, 7, 7, 2048, 512, 1, 1, 1, 0, 1000, "resnet_50:res5c_branch2a"},
    {1, 50, 7, 7, 512, 512, 3, 3, 1, 1, 1000, "resnet_50:res5c_branch2b"},
    {1, 50, 7, 7, 512, 2048, 1, 1, 1, 0, 1000, "resnet_50:res5c_branch2c"},
    // Topology: googlenet_v1
    {1, 32, 224, 224, 3, 64, 7, 7, 2, 3, 1000, "googlenet_v1:conv1/7x7_s2"},
    {1, 32, 56, 56, 64, 64, 1, 1, 1, 0, 1000, "googlenet_v1:conv2/3x3_reduce"},
    {1, 32, 56, 56, 64, 192, 3, 3, 1, 1, 1000, "googlenet_v1:conv2/3x3"},
    {1, 32, 28, 28, 192, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3a/1x1"},
    {1, 32, 28, 28, 192, 96, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3a/3x3_reduce"},
    {1, 32, 28, 28, 96, 128, 3, 3, 1, 1, 1000, "googlenet_v1:inception_3a/3x3"},
    {1, 32, 28, 28, 192, 16, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3a/5x5_reduce"},
    {1, 32, 28, 28, 16, 32, 5, 5, 1, 2, 1000, "googlenet_v1:inception_3a/5x5"},
    {1, 32, 28, 28, 192, 32, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3a/pool_proj"},
    {1, 32, 28, 28, 256, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3b/1x1"},
    {1, 32, 28, 28, 256, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3b/3x3_reduce"},
    {1, 32, 28, 28, 128, 192, 3, 3, 1, 1, 1000, "googlenet_v1:inception_3b/3x3"},
    {1, 32, 28, 28, 256, 32, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3b/5x5_reduce"},
    {1, 32, 28, 28, 32, 96, 5, 5, 1, 2, 1000, "googlenet_v1:inception_3b/5x5"},
    {1, 32, 28, 28, 256, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_3b/pool_proj"},
    {1, 32, 14, 14, 480, 192, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4a/1x1"},
    {1, 32, 14, 14, 480, 96, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4a/3x3_reduce"},
    {1, 32, 14, 14, 96, 208, 3, 3, 1, 1, 1000, "googlenet_v1:inception_4a/3x3"},
    {1, 32, 14, 14, 480, 16, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4a/5x5_reduce"},
    {1, 32, 14, 14, 16, 48, 5, 5, 1, 2, 1000, "googlenet_v1:inception_4a/5x5"},
    {1, 32, 14, 14, 480, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4a/pool_proj"},
    {1, 32, 4, 4, 512, 128, 1, 1, 1, 0, 1000, "googlenet_v1:loss1/conv"},
    {1, 32, 14, 14, 512, 160, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4b/1x1"},
    {1, 32, 14, 14, 512, 112, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4b/3x3_reduce"},
    {1, 32, 14, 14, 112, 224, 3, 3, 1, 1, 1000, "googlenet_v1:inception_4b/3x3"},
    {1, 32, 14, 14, 512, 24, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4b/5x5_reduce"},
    {1, 32, 14, 14, 24, 64, 5, 5, 1, 2, 1000, "googlenet_v1:inception_4b/5x5"},
    {1, 32, 14, 14, 512, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4b/pool_proj"},
    {1, 32, 14, 14, 512, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4c/1x1"},
    {1, 32, 14, 14, 512, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4c/3x3_reduce"},
    {1, 32, 14, 14, 128, 256, 3, 3, 1, 1, 1000, "googlenet_v1:inception_4c/3x3"},
    {1, 32, 14, 14, 512, 24, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4c/5x5_reduce"},
    {1, 32, 14, 14, 24, 64, 5, 5, 1, 2, 1000, "googlenet_v1:inception_4c/5x5"},
    {1, 32, 14, 14, 512, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4c/pool_proj"},
    {1, 32, 14, 14, 512, 112, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4d/1x1"},
    {1, 32, 14, 14, 512, 144, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4d/3x3_reduce"},
    {1, 32, 14, 14, 144, 288, 3, 3, 1, 1, 1000, "googlenet_v1:inception_4d/3x3"},
    {1, 32, 14, 14, 512, 32, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4d/5x5_reduce"},
    {1, 32, 14, 14, 32, 64, 5, 5, 1, 2, 1000, "googlenet_v1:inception_4d/5x5"},
    {1, 32, 14, 14, 512, 64, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4d/pool_proj"},
    {1, 32, 4, 4, 528, 128, 1, 1, 1, 0, 1000, "googlenet_v1:loss2/conv"},
    {1, 32, 14, 14, 528, 256, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4e/1x1"},
    {1, 32, 14, 14, 528, 160, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4e/3x3_reduce"},
    {1, 32, 14, 14, 160, 320, 3, 3, 1, 1, 1000, "googlenet_v1:inception_4e/3x3"},
    {1, 32, 14, 14, 528, 32, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4e/5x5_reduce"},
    {1, 32, 14, 14, 32, 128, 5, 5, 1, 2, 1000, "googlenet_v1:inception_4e/5x5"},
    {1, 32, 14, 14, 528, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_4e/pool_proj"},
    {1, 32, 7, 7, 832, 256, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5a/1x1"},
    {1, 32, 7, 7, 832, 160, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5a/3x3_reduce"},
    {1, 32, 7, 7, 160, 320, 3, 3, 1, 1, 1000, "googlenet_v1:inception_5a/3x3"},
    {1, 32, 7, 7, 832, 32, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5a/5x5_reduce"},
    {1, 32, 7, 7, 32, 128, 5, 5, 1, 2, 1000, "googlenet_v1:inception_5a/5x5"},
    {1, 32, 7, 7, 832, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5a/pool_proj"},
    {1, 32, 7, 7, 832, 384, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5b/1x1"},
    {1, 32, 7, 7, 832, 192, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5b/3x3_reduce"},
    {1, 32, 7, 7, 192, 384, 3, 3, 1, 1, 1000, "googlenet_v1:inception_5b/3x3"},
    {1, 32, 7, 7, 832, 48, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5b/5x5_reduce"},
    {1, 32, 7, 7, 48, 128, 5, 5, 1, 2, 1000, "googlenet_v1:inception_5b/5x5"},
    {1, 32, 7, 7, 832, 128, 1, 1, 1, 0, 1000, "googlenet_v1:inception_5b/pool_proj"},
    // Topology: googlenet_v2
    {1, 32, 224, 224, 3, 64, 7, 7, 2, 3, 1000, "googlenet_v2:conv1/7x7_s2"},
    {1, 32, 56, 56, 64, 64, 1, 1, 1, 0, 1000, "googlenet_v2:conv2/3x3_reduce"},
    {1, 32, 56, 56, 64, 192, 3, 3, 1, 1, 1000, "googlenet_v2:conv2/3x3"},
    {1, 32, 28, 28, 192, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3a/1x1"},
    {1, 32, 28, 28, 192, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3a/3x3_reduce"},
    {1, 32, 28, 28, 64, 64, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3a/3x3"},
    {1, 32, 28, 28, 192, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3a/double3x3_reduce"},
    {1, 32, 28, 28, 64, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3a/double3x3a"},
    {1, 32, 28, 28, 96, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3a/double3x3b"},
    {1, 32, 28, 28, 192, 32, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3a/pool_proj"},
    {1, 32, 28, 28, 256, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3b/1x1"},
    {1, 32, 28, 28, 256, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3b/3x3_reduce"},
    {1, 32, 28, 28, 64, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3b/3x3"},
    {1, 32, 28, 28, 256, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3b/double3x3_reduce"},
    {1, 32, 28, 28, 64, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3b/double3x3a"},
    {1, 32, 28, 28, 96, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3b/double3x3b"},
    {1, 32, 28, 28, 256, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3b/pool_proj"},
    {1, 32, 28, 28, 320, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3c/3x3_reduce"},
    {1, 32, 28, 28, 128, 160, 3, 3, 2, 1, 1000, "googlenet_v2:inception_3c/3x3"},
    {1, 32, 28, 28, 320, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_3c/double3x3_reduce"},
    {1, 32, 28, 28, 64, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_3c/double3x3a"},
    {1, 32, 28, 28, 96, 96, 3, 3, 2, 1, 1000, "googlenet_v2:inception_3c/double3x3b"},
    {1, 32, 4, 4, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:loss1/conv"},
    {1, 32, 14, 14, 576, 224, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4a/1x1"},
    {1, 32, 14, 14, 576, 64, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4a/3x3_reduce"},
    {1, 32, 14, 14, 64, 96, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4a/3x3"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4a/double3x3_reduce"},
    {1, 32, 14, 14, 96, 128, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4a/double3x3a"},
    {1, 32, 14, 14, 128, 128, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4a/double3x3b"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4a/pool_proj"},
    {1, 32, 14, 14, 576, 192, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4b/1x1"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4b/3x3_reduce"},
    {1, 32, 14, 14, 96, 128, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4b/3x3"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4b/double3x3_reduce"},
    {1, 32, 14, 14, 96, 128, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4b/double3x3a"},
    {1, 32, 14, 14, 128, 128, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4b/double3x3b"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4b/pool_proj"},
    {1, 32, 14, 14, 576, 160, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4c/1x1"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4c/3x3_reduce"},
    {1, 32, 14, 14, 128, 160, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4c/3x3"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4c/double3x3_reduce"},
    {1, 32, 14, 14, 128, 160, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4c/double3x3a"},
    {1, 32, 14, 14, 160, 160, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4c/double3x3b"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4c/pool_proj"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4d/1x1"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4d/3x3_reduce"},
    {1, 32, 14, 14, 128, 192, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4d/3x3"},
    {1, 32, 14, 14, 576, 160, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4d/double3x3_reduce"},
    {1, 32, 14, 14, 160, 192, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4d/double3x3a"},
    {1, 32, 14, 14, 192, 192, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4d/double3x3b"},
    {1, 32, 14, 14, 576, 96, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4d/pool_proj"},
    {1, 32, 14, 14, 576, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4e/3x3_reduce"},
    {1, 32, 14, 14, 128, 192, 3, 3, 2, 1, 1000, "googlenet_v2:inception_4e/3x3"},
    {1, 32, 14, 14, 576, 192, 1, 1, 1, 0, 1000, "googlenet_v2:inception_4e/double3x3_reduce"},
    {1, 32, 14, 14, 192, 256, 3, 3, 1, 1, 1000, "googlenet_v2:inception_4e/double3x3a"},
    {1, 32, 14, 14, 256, 256, 3, 3, 2, 1, 1000, "googlenet_v2:inception_4e/double3x3b"},
    {1, 32, 2, 2, 1024, 128, 1, 1, 1, 0, 1000, "googlenet_v2:loss2/conv"},
    {1, 32, 7, 7, 1024, 352, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5a/1x1"},
    {1, 32, 7, 7, 1024, 192, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5a/3x3_reduce"},
    {1, 32, 7, 7, 192, 320, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5a/3x3"},
    {1, 32, 7, 7, 1024, 160, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5a/double3x3_reduce"},
    {1, 32, 7, 7, 160, 224, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5a/double3x3a"},
    {1, 32, 7, 7, 224, 224, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5a/double3x3b"},
    {1, 32, 7, 7, 1024, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5a/pool_proj"},
    {1, 32, 7, 7, 1024, 352, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5b/1x1"},
    {1, 32, 7, 7, 1024, 192, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5b/3x3_reduce"},
    {1, 32, 7, 7, 192, 320, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5b/3x3"},
    {1, 32, 7, 7, 1024, 192, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5b/double3x3_reduce"},
    {1, 32, 7, 7, 192, 224, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5b/double3x3a"},
    {1, 32, 7, 7, 224, 224, 3, 3, 1, 1, 1000, "googlenet_v2:inception_5b/double3x3b"},
    {1, 32, 7, 7, 1024, 128, 1, 1, 1, 0, 1000, "googlenet_v2:inception_5b/pool_proj"},
};
