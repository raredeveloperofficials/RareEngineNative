#pragma once
#include <string>
const char* vertexShaderStart =  R"(#version 300 es
uniform mat4 umvp;
uniform mat4 umodel;
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUV;
layout(location = 2) in vec3 aNorm;
out vec3 vpos;
out vec2 vuv;
out vec3 vnorm;
)";
const char* vertexShaderEnd = R"(
vuv = aUV;

vpos = vec3(umodel * vec4(aPos, 1.0));

vnorm = mat3(umodel) * aNorm;
)";
const char* fragmentShaderStart = R"(#version 300 es
precision mediump float;

uniform vec4 vcol;

in vec3 vpos;
in vec3 vnorm;
in vec2 vuv;

out vec4 FragColor;
)";
const char* diffuseVars = R"(
uniform vec3 sunDir;
uniform vec3 ambient;
uniform vec3 sunColor;
uniform float hasSun;
uniform float disableLight;
)";


const char* diffuse = R"(
vec3 normal = normalize(vnorm);

vec3 lightDir = normalize(-sunDir);

vec3 diffuse = max(dot(normal, lightDir), 0.0) * sunColor;

vec3 light = ambient + (hasSun > 0.5 ? diffuse : vec3(0.0));

if(disableLight == 1.0){
    light = vec3(1.0);
}
)";


const char* lightVars = R"(
struct PointLight{
    vec3 color;
    vec3 position;
    float fade;
    float range;
    float intensity;
};

struct SpotLight{
    vec3 color;
    vec3 position;
    vec3 direction;
    float fade;
    float angle;
    float range;
    float intensity;
};

uniform PointLight pointLights[10];
uniform SpotLight spotLights[10];

uniform int pointLightCount;
uniform int spotLightCount;
)";


const char* lightFuncs = R"(
float getPointAttenuation(PointLight light, vec3 fragPos){
    if(light.fade < 0.5) return 1.0;

    float r = max(light.range, 0.0001);
    float d = length(light.position - fragPos);

    if(d >= r) return 0.0;

    return 1.0 - (d / r);
}

float getSpotAttenuation(SpotLight light, vec3 fragPos){
    if(light.fade < 0.5) return 1.0;

    float r = max(light.range, 0.0001);
    float d = length(light.position - fragPos);

    if(d >= r) return 0.0;

    return 1.0 - (d / r);
}

float getSpotFactor(SpotLight light, vec3 fragPos){
    vec3 toFrag = normalize(fragPos - light.position);
    vec3 dir = normalize(-light.direction);

    float theta = dot(toFrag, dir);
    float cutoff = cos(radians(light.angle));

    return smoothstep(cutoff, 1.0, theta);
}
)";


const char* light = R"(
if(disableLight == 1.0){
    light = vec3(1.0);
}
else{

    for(int i = 0; i < min(pointLightCount, 10); i++){

        vec3 n = normalize(normal);
        vec3 pDir = normalize(pointLights[i].position - vpos);

        float pDiffuse = max(dot(n, pDir), 0.0);
        float pAtt = getPointAttenuation(pointLights[i], vpos);

        light += pointLights[i].color
               * pDiffuse
               * pAtt
               * pointLights[i].intensity;
    }


    for(int i = 0; i < min(spotLightCount, 10); i++){

        vec3 toLight = normalize(spotLights[i].position - vpos);
        vec3 n = normalize(normal);

        float sDiffuse = max(dot(n, toLight), 0.0);

        float sAtt = getSpotAttenuation(spotLights[i], vpos);
        float sCone = getSpotFactor(spotLights[i], vpos);

        light += spotLights[i].color
               * sDiffuse
               * sAtt
               * sCone
               * spotLights[i].intensity;
    }
}
)";


const char* basicVertexRESL = R"(--impl--

void main(){
    gl_Position = umvp * vec4(aPos, 1.0);

--end--
}
)";


const char* basicFragmentRESL = R"(--impl--

u: sampler2D tex;

--diffuse_vars--
--light_vars--
--light_functions--

void main(){

    vec4 texColor = texture(tex, vuv);

    --diffuse--
    --light--

    FragColor = vec4(
        texColor.rgb * vcol.rgb * light,
        texColor.a * vcol.a
    );
}
)";
const char* Position    = "aPos";
const char* MVP         = "umvp";
const char* Vertex_UV   = "aUV";
const char* Fragment_UV = "vuv";
const char* Color       = "vcol";

void replaceAll(
    std::string& str,
    const std::string& from,
    const std::string& to
){
    if(from.empty())
        return;

    size_t pos = 0;

    while((pos = str.find(from, pos)) != std::string::npos){
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}
std::string toVertexShader(std::string shader)
{
    replaceAll(shader, "--impl--", vertexShaderStart);
    replaceAll(shader, "--end--", vertexShaderEnd);
    replaceAll(shader, "loc(", "layout(location =");
    replaceAll(shader, "u:", "uniform");

    return shader;
}
std::string toFragmentShader(std::string shader)
{
    replaceAll(shader, "--impl--", fragmentShaderStart);
    replaceAll(shader, "loc(", "layout(location =");
    replaceAll(shader, "u:", "uniform");

    replaceAll(shader, "--diffuse_vars--", diffuseVars);
    replaceAll(shader, "--diffuse--", diffuse);
    replaceAll(shader, "--light_vars--", lightVars);
    replaceAll(shader, "--light--", light);
    replaceAll(shader, "--light_functions--", lightFuncs);

    return shader;
}