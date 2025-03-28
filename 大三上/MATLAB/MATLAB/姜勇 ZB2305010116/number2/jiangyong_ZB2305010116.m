function varargout = jiangyong_ZB2305010116(varargin)
% JIANGYONG_ZB2305010116 MATLAB code for jiangyong_ZB2305010116.fig
%      JIANGYONG_ZB2305010116, by itself, creates a new JIANGYONG_ZB2305010116 or raises the existing
%      singleton*.
%
%      H = JIANGYONG_ZB2305010116 returns the handle to a new JIANGYONG_ZB2305010116 or the handle to
%      the existing singleton*.
%
%      JIANGYONG_ZB2305010116('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in JIANGYONG_ZB2305010116.M with the given input arguments.
%
%      JIANGYONG_ZB2305010116('Property','Value',...) creates a new JIANGYONG_ZB2305010116 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before jiangyong_ZB2305010116_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to jiangyong_ZB2305010116_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help jiangyong_ZB2305010116

% Last Modified by GUIDE v2.5 24-Dec-2023 16:08:47

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @jiangyong_ZB2305010116_OpeningFcn, ...
                   'gui_OutputFcn',  @jiangyong_ZB2305010116_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before jiangyong_ZB2305010116 is made visible.
function jiangyong_ZB2305010116_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to jiangyong_ZB2305010116 (see VARARGIN)

% Choose default command line output for jiangyong_ZB2305010116
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes jiangyong_ZB2305010116 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = jiangyong_ZB2305010116_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA
% 使用audioread读取音频文件 "叽叽.wav"将采样率存储在 fs 中，音频信号存储在 data 中。
[data,fs]=audioread('叽叽.wav');

%将data矩阵转置并选择第一列（即单声道音频数据）。如果原始音频是立体声的（双声道），这步操作将其转换为单声道。
data=data(:,1)';
%使用sound函数播放处理后的音频数据
sound(data,fs);



% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=4500;% 设置噪声频率为4500Hz  
% 向原始音频信号中添加单频噪声，这里乘以0.5是为了减小噪声强度
data_noise=data+0.5*sin(2*pi*fn*t);
% 使用sound函数播放处理后的音频信号，fs是采样频率  
sound(data_noise,fs);


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=4500;%噪声频率
data_noise=data+0.5*sin(2*pi*fn*t);%加入单频噪声
data_noise_fft=fft(data_noise,N);
data_1=fs/N;
% 设置滤波器的采样频率为40000Hz，截止频率为10000Hz  
fs = 40000; % 采样频率
fc = 10000; % 截止频率
[b, a] = butter(5, fc/(fs/2), 'low'); % 设计一个5阶低通滤波器  

% 对频谱进行滤波
data_noise_fft_filtered = filter(b, a, data_noise_fft);

% 生成频率向量  
F = 0:data_1:(N-1)*data_1;
axes(handles.axes2);
plot(F,abs(data_noise_fft_filtered));
title('滤波后的幅度谱','color','r');
xlabel('频率 (Hz)');
ylabel('幅度');


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=4500;%噪声频率
data_noise=data+0.5*sin(2*pi*fn*t);%加入单频噪声
data_noise_fft=fft(data_noise,N);
data_1=fs/N;
% 逆傅里叶变换
data_noise_ifft = ifft(data_noise_fft);

% 设计低通滤波器
numtaps = 50; % 滤波器系数数量
cutoff_freq = 1000; % 截止频率
[b, a] = fir1(numtaps, cutoff_freq / (fs / 2));

% 应用滤波器对信号进行处理  
data_filtered = filter(b, a, data_noise_ifft);

% 对处理后的信号进行傅里叶变换  
data_filtered_fft = fft(data_filtered);

data_filtered=filter(b,a,data_noise);
sound(data_filtered,fs);

% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
% 计算采样周期  
T=1/fs;
% 获取数据长度  
N=length(data);
% 生成时间向量  
t=0:T:(N-1)*T;
% 指定绘图轴为handles.axes2
axes(handles.axes2);
% 绘制时域波形图  
plot(t,data);
title('原始语音信号的时域波形','color','r');
xlabel('时间'); % 添加 x 轴标签
ylabel('幅值');

% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
% 对数据进行快速傅里叶变换，N是FFT的点数  
data_fft=fft(data,N);
% 计算频率分辨率，即两个相邻的谱线之间的频率差  
data_1=fs/N;
% 生成频率向量  
F=0:data_1:(N-1)*data_1;
% 指定绘图轴为handles.axes2
axes(handles.axes2);
% 绘制幅度谱图，使用绝对值函数abs来绘制振幅谱，因为FFT的结果通常是复数，使用abs可以得到幅值谱 
plot(F,abs(data_fft));
title('原始语音信号的幅度谱','color','r');
xlabel('频率 (Hz)');
ylabel('幅度');

% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=4500;%噪声频率
data_noise=data+0.5*sin(2*pi*fn*t);%加入单频噪声
axes(handles.axes2);
% 绘制加噪后的语音信号的时域波形图  
plot(t,data_noise);
title('加噪语音信号的时域波形','color','r');
xlabel('时间 (s)');
ylabel('幅度');


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=4500;%噪声频率
data_noise=data+0.5*sin(2*pi*fn*t);%加入单频噪声
% 对加噪后的音频信号进行快速傅里叶变换，N是FFT的点数 
data_noise_fft=fft(data_noise,N);
% 计算频率分辨率，即两个相邻的谱线之间的频率差  
data_1=fs/N;
% 生成频率向量 
F=0:data_1:(N-1)*data_1;
axes(handles.axes2);
% 绘制加噪后的语音信号的幅度谱图，使用绝对值函数abs来绘制振幅谱，因为FFT的结果通常是复数，使用abs可以得到幅值谱
plot(F,abs(data_noise_fft));
title('加噪语音信号的幅度谱','color','r');
xlabel('频率 (Hz)');
ylabel('幅度');


% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[data,fs]=audioread('叽叽.wav');
data=data(:,1)';
T=1/fs;
N=length(data);
t=0:T:(N-1)*T;
fn=10000;%噪声频率
data_noise=data+0.5*sin(2*pi*fn*t);%加入单频噪声
data_noise_fft=fft(data_noise,N);
data_1=fs/N;
F=0:data_1:(N-1)*data_1;
% 逆傅里叶变换，将频域信号转换回时域信号
data_noise_ifft = ifft(data_noise_fft);
% 设计低通滤波器
numtaps = 50; % 滤波器系数数量
cutoff_freq = 1000; % 截止频率
[b, a] = fir1(numtaps, cutoff_freq / (fs / 2));
% 应用滤波器
data_filtered = filter(b, a, data_noise_ifft);
% 再次进行傅里叶变换
data_filtered_fft = fft(data_filtered);
axes(handles.axes2);
plot(data_filtered,abs(data_noise_fft));
title('去噪语音信号的幅度谱','color','r');
xlabel('频率 (Hz)');
ylabel('幅度');


% --- Executes during object creation, after setting all properties.
function pushbutton3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function pushbutton4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
