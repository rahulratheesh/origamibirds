varying vec2 v_texCoord;
varying vec3 v_norCoord;

uniform vec3 u_color;
uniform vec3 u_ambient;
uniform sampler2D u_sampler;

struct BaseLight
{
    vec3 color;
    float intensity;
};

struct DirectionalLight
{
    BaseLight baseLight;
    vec3 direction;
};

uniform DirectionalLight u_directionalLight;

vec4 calculateLight(BaseLight baseLight, vec3 direction, vec3 normal)
{
    float kd = dot(normal, direction);
    vec4 diffuseColor = vec4(0.0, 0.0, 0.0, 0.0);
    if (kd > 0.0)
    {
        diffuseColor = vec4(baseLight.color, 1.0) * baseLight.intensity * kd;
    }
    return diffuseColor;
}

vec4 calculateDirectionalLight(DirectionalLight directionalLight, vec3 normal)
{
    return calculateLight(directionalLight.baseLight, -directionalLight.direction, normal);
}


void main(void) {

    vec4 totalLight = vec4(u_ambient, 1.0);
    vec4 textureColor = texture2D(u_sampler, v_texCoord);
    vec4 baseColor = vec4(u_color, 1.0);

    if (textureColor.x != 0.0 && textureColor.y != 0.0)
        baseColor *= textureColor;

    vec3 normal = normalize(v_norCoord);
    totalLight += calculateDirectionalLight(u_directionalLight, normal);

    gl_FragColor = baseColor * totalLight;
}
