attribute vec3 a_posCoord;
attribute vec2 a_texCoord;
attribute vec3 a_norCoord;

varying vec2 v_texCoord;
varying vec3 v_norCoord;

uniform mat4 u_transform;
uniform mat4 u_normal_transform;

void main(void) {
    gl_Position = u_transform * vec4(a_posCoord, 1.0);
    v_texCoord = a_texCoord;
    v_norCoord = (u_normal_transform * vec4(a_norCoord, 1.0)).xyz;
}
