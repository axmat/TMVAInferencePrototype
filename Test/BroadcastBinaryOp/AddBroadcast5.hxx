//Code generated automatically by TMVA for Inference of Model file [AddBroadcast5.onnx] at [Wed Oct  5 12:32:30 2022] 

#ifndef TMVA_SOFIE_ADDBROADCAST5
#define TMVA_SOFIE_ADDBROADCAST5

#include<vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_AddBroadcast5{
struct Session {
std::vector<float> fTensor_Y = std::vector<float>(24);
float * tensor_Y = fTensor_Y.data();
std::vector<float> fTensor_BroadcastedA = std::vector<float>(24);
float * tensor_BroadcastedA = fTensor_BroadcastedA.data();


Session(std::string filename ="") {
   if (filename.empty()) filename = "AddBroadcast5.dat";
}

std::vector<float> infer(float* tensor_B,float* tensor_A){
   
//------ Add
   // Broadcasting uninitialized tensor A
   {
      float* data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_A, { 2 , 1 , 4 }, { 2 , 3 , 4 });
      std::copy(data, data + 24, tensor_BroadcastedA);
      delete[] data;
   }
   for (size_t id = 0; id < 24 ; id++){
      tensor_Y[id] = tensor_BroadcastedA[id] + tensor_B[id] ;
   }
   std::vector<float> ret (tensor_Y, tensor_Y + 24);
   return ret;
}
};
} //TMVA_SOFIE_AddBroadcast5

#endif  // TMVA_SOFIE_ADDBROADCAST5
