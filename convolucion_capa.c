#include "convolucion_capa.h"

void convIniciar(conv_op *conv, int stride, int cant_kernel, int altura_imagen, int tam_lado_kernel){
    conv->tam_lado_kernel = tam_lado_kernel;
    conv->stride = stride;
    conv->cant_kernel = cant_kernel;
    conv->tam_matriz_result = altura_imagen;
    conv->padding = (-altura_imagen+tam_lado_kernel-stride+(stride*altura_imagen))/2;
    conv->kernel_matriz = (kernel*)malloc(cant_kernel*sizeof(kernel));
    conv->result_conv = (conv_out*)malloc(cant_kernel*sizeof(conv_out));
    conv->bias_matriz = (bias*)malloc(cant_kernel*sizeof(bias));
    conv->matriz_temp_padding = (float**)malloc((altura_imagen+(conv->padding*2))*sizeof(float *));

    conv->tam_matriz_temp = (altura_imagen+(conv->padding*2));
    for(int i=0; i<altura_imagen+(conv->padding*2);i++){
        conv->matriz_temp_padding[i]= (float*)malloc((altura_imagen+(conv->padding*2))*sizeof(float));
        for(int j = 0; j<altura_imagen+(conv->padding*2); j++){
            conv->matriz_temp_padding[i][j]=0;
        }
    }
}

void iniciarMatrizConv(conv_op *conv){
    
    for(int i = 0;i<conv->cant_kernel;i++){
        conv->kernel_matriz[i].matriz = (float**)malloc(conv->tam_lado_kernel*sizeof(float *));
        conv->bias_matriz[i].matriz = (float**)malloc(conv->tam_lado_kernel*sizeof(float *));
        for(int j=0; j<conv->tam_lado_kernel;j++){
            conv->kernel_matriz[i].matriz[j] = (float*)malloc(conv->tam_lado_kernel*sizeof(float));
            conv->bias_matriz[i].matriz[j] = (float*)malloc(conv->tam_lado_kernel*sizeof(float));
            for(int h=0; h<conv->tam_lado_kernel;h++){
                conv->kernel_matriz[i].matriz[j][h]=0;
                conv->bias_matriz[i].matriz[j][h]=0;
            }
        }

    }

    //Test
    for(int i=0;i<conv->tam_lado_kernel;i++){
        for(int j=0; j<conv->tam_lado_kernel;j++){
            
            if(i==j){
                
                conv->kernel_matriz[1].matriz[i][j]=1.0;
            }
        }
    }

    for(int i = 0; i< conv->cant_kernel; i++){
        
        conv->result_conv[i].matriz= (float**)malloc(conv->tam_matriz_result *sizeof(float *));
        for(int j = 0; j<conv->tam_matriz_result;j++){
            conv->result_conv[i].matriz[j] = (float*)malloc(conv->tam_matriz_result *sizeof(float));
        }
    }
}

void vuelco_matriz_temporal(infoImagen *imagen, conv_op *conv){
    
    for(int i = 0; i<imagen->tam_lado;i++){
        for(int j=0;j<imagen->tam_lado;j++){
            
            conv->matriz_temp_padding[i+conv->padding][j+conv->padding]=(float)imagen->matriz[i][j];


        }
    }
 
}

void pasada_kernel(conv_op *conv){
    int x=0;
    int resultado = 0;

    for(int x = 0; x<conv->cant_kernel;x++){
        for(int i = 0;i<conv->tam_matriz_result;i++){
            
            for(int j = 0; j<conv->tam_matriz_result;j++){
                resultado=0;
                for(int h=0; h<conv->tam_lado_kernel;h++){
                    for(int l=0;l<conv->tam_lado_kernel;l++){
                        if((i+l)<conv->tam_matriz_temp && (j+h)<conv->tam_matriz_temp){
                            resultado+=conv->matriz_temp_padding[i+l][j+h]*conv->kernel_matriz[1].matriz[h][l]+conv->bias_matriz[x].matriz[h][l];
                        }   
                    }
                }

                //Convolucion y ReLu
                if(resultado >=0){
                    conv->result_conv[x].matriz[i][j]=resultado;
                }else{
                    conv->result_conv[x].matriz[i][j]=0;
                }
                

           
            }
        }
    }
    
}

