attribute vec3 a_posCoord;
attribute vec2 a_texCoord;

varying vec2 v_texCoord;

uniform mat4 u_transform;

void main(void) {
    gl_Position = u_transform * vec4(a_posCoord, 1.0);
    v_texCoord = a_texCoord;

}
